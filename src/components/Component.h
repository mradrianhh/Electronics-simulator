#pragma once

#include "Node.h"

class Component : public Node
{
    private:
    double voltage_drop_; // If positive, voltage gain.

    public:
    Component(double voltage_drop);
    double voltage_drop();
};