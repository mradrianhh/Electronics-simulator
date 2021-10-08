#pragma once
#include "Node.h"
#include <string>

class Resistor : public Node
{
    double resistance_;

    public:
    Resistor(std::string name, double resistance);
    double resistance();
    void set_resistance(double resistance);
};