#pragma once

#include "Node.h"

class VoltageSource : public Node
{
    private:
    double voltage_;

    public:
    VoltageSource(double voltage);
    VoltageSource(std::string name, double voltage);
    double voltage();
};