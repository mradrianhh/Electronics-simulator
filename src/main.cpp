#include <iostream>

#include "./components/Node.h"
#include "./components/VoltageSource.h"
#include "./components/Circuit.h"

using namespace std;

int main()
{
    VoltageSource vs("12V Power supply", 12.0);
    Node node1("Node 1");
    Node node2("Node 2");

    Circuit circuit(&vs);
    circuit.add_node_series(&node1);
    circuit.add_node_series(&node2);
    circuit.display_circuit();
};