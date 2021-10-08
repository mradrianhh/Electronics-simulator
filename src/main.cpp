#include <iostream>

#include "./components/Node.h"
#include "./components/VoltageSource.h"
#include "./components/Component.h"

using namespace std;

int main()
{
    Node node;
    VoltageSource vs(12.0);
    Component component(12);

    cout << node.id() << endl;
    cout << vs.id() << " - " << vs.voltage() << endl;
    cout << component.id() << " - " << component.voltage_drop() << endl;
};