#include "VoltageSource.h"

VoltageSource::VoltageSource(double voltage)
{
    voltage_ = voltage;
};

double VoltageSource::voltage()
{
    return voltage_;
};