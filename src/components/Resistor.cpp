#include "Resistor.h"

Resistor::Resistor(std::string name, double resistance) : Node(name)
{
    resistance_ = resistance;
};

double Resistor::resistance()
{
    return resistance_;
};

void Resistor::set_resistance(double resistance)
{
    resistance_ = resistance;
};