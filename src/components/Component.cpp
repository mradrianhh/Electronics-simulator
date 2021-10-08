#include "Component.h"

Component::Component(double voltage_drop)
{
    voltage_drop_ = voltage_drop;
};

double Component::voltage_drop()
{
    return voltage_drop_;
};