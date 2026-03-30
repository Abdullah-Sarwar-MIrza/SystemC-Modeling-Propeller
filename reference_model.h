#ifndef PROPELLER_REFERENCE_MODEL_H
#define PROPELLER_REFERENCE_MODEL_H

#include <systemc-ams>

SCA_TDF_MODULE(reference)
{
    sca_tdf::sca_out<double> ref;

    SCA_CTOR(reference);

    void set_attributes();
    void processing();
};

#endif
