#pragma once

#include "Node.h"

class VoltageSource : public Node
{
    private:
    double voltage_;

    public:
    VoltageSource(double voltage);
    double voltage();
};