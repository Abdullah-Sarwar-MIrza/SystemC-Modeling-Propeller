#ifndef PROPELLER_BOOM_SYSTEM_H
#define PROPELLER_BOOM_SYSTEM_H

#include <systemc-ams>

SCA_TDF_MODULE(boom_dynamics)
{
    sca_tdf::sca_in<double> speed;
    sca_tdf::sca_out<double> angle;

    double inertia;
    double angle_state;

    boom_dynamics(sc_core::sc_module_name nm);

    void set_attributes();
    void initialize();
    void processing();
};

#endif
