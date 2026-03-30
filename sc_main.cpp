#include <systemc-ams.h>

#include "Motor_module.h"
#include "PID_controller_module.h"
#include "boom_system.h"
#include "hall_sensor.h"
#include "reference_model.h"

int sc_main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    sca_tdf::sca_signal<double> ref_sig;
    sca_tdf::sca_signal<double> meas_sig;
    sca_tdf::sca_signal<double> ctrl_sig;
    sca_tdf::sca_signal<double> speed_sig;
    sca_tdf::sca_signal<double> angle_sig;

    reference ref("ref");

    pid_controller pid("pid", 2.0, 0.5, 0.1);
    motor m("motor");
    boom_dynamics boom("boom");
    hall_sensor sensor("sensor");

    ref.ref(ref_sig);

    pid.ref(ref_sig);
    pid.meas(meas_sig);
    pid.out(ctrl_sig);

    m.voltage(ctrl_sig);
    m.speed(speed_sig);

    boom.speed(speed_sig);
    boom.angle(angle_sig);

    sensor.real_angle(angle_sig);
    sensor.measured_angle(meas_sig);

    // Create VCD trace file
    sca_util::sca_trace_file* tf_vcd;
    tf_vcd = sca_util::sca_create_vcd_trace_file("tr");
    sca_util::sca_trace(tf_vcd, ref_sig, "reference");
    sca_util::sca_trace(tf_vcd, meas_sig, "measured_angle");
    sca_util::sca_trace(tf_vcd, ctrl_sig, "control_signal");
    sca_util::sca_trace(tf_vcd, speed_sig, "motor_speed");
    sca_util::sca_trace(tf_vcd, angle_sig, "boom_angle");

    // Create tabular (DAT) trace file
    sca_util::sca_trace_file* tf_dat;
    tf_dat = sca_util::sca_create_tabular_trace_file("tr.dat");
    sca_util::sca_trace(tf_dat, ref_sig, "reference");
    sca_util::sca_trace(tf_dat, meas_sig, "measured_angle");
    sca_util::sca_trace(tf_dat, ctrl_sig, "control_signal");
    sca_util::sca_trace(tf_dat, speed_sig, "motor_speed");
    sca_util::sca_trace(tf_dat, angle_sig, "boom_angle");

    sc_core::sc_start(5, sc_core::SC_SEC);

    sca_util::sca_close_vcd_trace_file(tf_vcd);
    sca_util::sca_close_tabular_trace_file(tf_dat);

    return 0;
}