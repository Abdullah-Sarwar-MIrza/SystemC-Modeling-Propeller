#ifndef PROPELLER_PID_CONTROLLER_MODULE_H
#define PROPELLER_PID_CONTROLLER_MODULE_H

#include <systemc-ams>

SCA_TDF_MODULE(pid_controller)
{
    sca_tdf::sca_in<double> ref;
    sca_tdf::sca_in<double> meas;
    sca_tdf::sca_out<double> out;

    double Kp;
    double Ki;
    double Kd;

    double integral;
    double prev_error;

    pid_controller(sc_core::sc_module_name nm, double kp, double ki, double kd);

    void initialize();
    void processing();
};

#endif
