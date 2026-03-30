#include "Motor_module.h"

motor::motor(sc_core::sc_module_name nm)
: voltage("voltage"), speed("speed"),
  tau(0.2), speed_state(0.0)
{}

void motor::set_attributes()
{
    // Break feedback loop in the TDF cluster.
    speed.set_delay(1);
}

void motor::initialize()
{
    speed_state = 0.0;
    speed.initialize(speed_state);
}

void motor::processing()
{
    const double dt = get_timestep().to_seconds();
    const double v = voltage.read();
    const double dw = (v - speed_state) / tau;

    speed_state += dw * dt;
    speed.write(speed_state);
}
