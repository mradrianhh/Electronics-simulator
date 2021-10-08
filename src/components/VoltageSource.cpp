#include "VoltageSource.h"
#include <iostream>

VoltageSource::VoltageSource(double voltage)
{
    voltage_ = voltage;
};

VoltageSource::VoltageSource(std::string name, double voltage) : Node(name)
{
    voltage_ = voltage;
}

double VoltageSource::voltage()
{
    return voltage_;
};