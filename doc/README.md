# Electronics-simulator

# Design:

Voltage source(Node) - parent:
    - Node
    - Component(Node)
    ... Children

# Node design:

Node attributes:
    - ID
    - Attached nodes(components)
    - Component

# Data structure:

Nodes are connected in the form of a circular linked list.
When moving through the list, if the next node has the same id as the entry-node, the loop is finished.
The nodes also needs to keep track of the previous node(s).

# Circuit traversal

1. node = entry_node. Mark node checked.
2. If next node == entry_node, quit.
3. If len(next) == 1, set node = next. Mark node checked. Goto 2.
4. Else, push node to stack. set node = next.first. Mark node checked.
5. If len(next) == 1, set node = next. Mark node checked.
6. If len(node.prev) > 1, node = stack.pop.
7. Else if len(node.next) > 1, goto 4.
8. Else if len(node.next) == 1, set node = next. Mark node checked.


# Node analysis:

Check currents going into and out of the node.
If component associated with node, calculate voltage drop, etc.
Check associated components/nodes.

# Branching algorithm:

Start at entry node.
Perform node-analysis.
If one associated node/component/
    continue to it.
Elif multiple
    start one thread for each node/component, and proceed as usual.
For each node, check node_id across threads.
If thread_1.node_id == thread_2.node_id
    join(thread_1, thread_2)
If thread.node_id == entry_node.id
    exit()

# Example - Series RC-circuit.

Voltage source(12V) = start_node
loop = {start_node, R_node, C_node}
for(node in loop) => loop start
start_node -> R_node => voltage drop across R_node.component
R_node -> C_node => voltage drop across C_node.component
C_node -> start_node => loop exit

# Example - paralell RC-circuit

Voltage source = start_node
Resistor = r_node
Capacitor = c_node

start_node.associated_components = {r_node, c_node}
r_node.associated_components = {start_node}
c_node.associated_components = {start_node}

loop = {start_node, r_node, c_node}

voltage_source = 0


def circuit_analysis(start_node):
    RUNNING = True

    node = start_node
    while(RUNNING)
        voltage_source += node.voltage_drop
        associated_components = start_node.associated_components
        if length(associated_components) == 1:
            node = associated_components[0]
        else:
            for(component in associated_components):
                start_thread(circuit_analysis, component)


