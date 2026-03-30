#include "boom_system.h"

boom_dynamics::boom_dynamics(sc_core::sc_module_name nm)
: speed("speed"), angle("angle"),
  inertia(0.5), angle_state(0.0)
{}

void boom_dynamics::set_attributes()
{
    // Break feedback loop in the TDF cluster.
    angle.set_delay(1);
}

void boom_dynamics::initialize()
{
    angle_state = 0.0;
    angle.initialize(angle_state);
}

void boom_dynamics::processing()
{
    const double dt = get_timestep().to_seconds();
    angle_state += speed.read() * dt / inertia;
    angle.write(angle_state);
}
