#include <iostream>

#include "./components/Node.h"
#include "./components/VoltageSource.h"
#include "./components/Component.h"
#include "./components/Loop.h"

using namespace std;

int main()
{
    VoltageSource vs("12V Power supply", 12.0);
    Node node1("Node 1");
    Node node2("Node 2");

    Loop loop(&vs);
    loop.add_node(&node1);
    loop.add_node(&node2);
    loop.display_nodes();
};