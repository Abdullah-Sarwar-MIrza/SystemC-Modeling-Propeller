#include "PID_controller_module.h"

pid_controller::pid_controller(sc_core::sc_module_name nm,
                               double kp, double ki, double kd)
: ref("ref"), meas("meas"), out("out"),
  Kp(kp), Ki(ki), Kd(kd),
  integral(0.0), prev_error(0.0)
{}

void pid_controller::initialize()
{
    integral = 0.0;
    prev_error = 0.0;
}

void pid_controller::processing()
{
    const double dt = get_timestep().to_seconds();
    const double error = ref.read() - meas.read();

    integral += error * dt;
    const double derivative = (error - prev_error) / dt;

    const double control = Kp * error + Ki * integral + Kd * derivative;
    out.write(control);

    prev_error = error;
}
