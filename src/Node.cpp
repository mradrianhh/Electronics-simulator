#include <Node.h>

Node::Node(double voltage_drop)
{
    s_count_++;
    id_ = s_count_;
    set_voltage_drop(voltage_drop)
}

void Node::set_voltage_drop(double voltage_drop)
{
    voltage_drop_ = voltage_drop
}