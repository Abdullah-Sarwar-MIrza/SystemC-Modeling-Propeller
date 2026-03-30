#include "hall_sensor.h"

#include <cstdlib>

hall_sensor::hall_sensor(sc_core::sc_module_name nm)
: real_angle("real_angle"), measured_angle("measured_angle")
{}

void hall_sensor::set_attributes()
{
    measured_angle.set_delay(1);
}

void hall_sensor::initialize()
{
    measured_angle.initialize(0.0);
}

void hall_sensor::processing()
{
    const double noise = (std::rand() % 100) / 10000.0;
    measured_angle.write(real_angle.read() + noise);
}
