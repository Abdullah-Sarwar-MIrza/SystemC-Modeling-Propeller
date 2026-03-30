#ifndef PROPELLER_MOTOR_MODULE_H
#define PROPELLER_MOTOR_MODULE_H

#include <systemc-ams>

SCA_TDF_MODULE(motor)
{
    sca_tdf::sca_in<double> voltage;
    sca_tdf::sca_out<double> speed;

    double tau;
    double speed_state;

    motor(sc_core::sc_module_name nm);

    void set_attributes();
    void initialize();
    void processing();
};

#endif
