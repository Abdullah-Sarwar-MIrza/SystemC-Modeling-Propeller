#include "reference_model.h"

reference::reference(sc_core::sc_module_name nm)
: ref("ref")
{}

void reference::set_attributes()
{
    ref.set_timestep(1.0, sc_core::SC_MS);
}

void reference::processing()
{
    ref.write(35.0);
}
