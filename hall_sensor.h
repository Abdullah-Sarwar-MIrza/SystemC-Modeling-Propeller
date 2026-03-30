#ifndef PROPELLER_HALL_SENSOR_H
#define PROPELLER_HALL_SENSOR_H

#include <systemc-ams>

SCA_TDF_MODULE(hall_sensor)
{
    sca_tdf::sca_in<double> real_angle;
    sca_tdf::sca_out<double> measured_angle;

    SCA_CTOR(hall_sensor);

    void set_attributes();
    void initialize();
    void processing();
};

#endif
