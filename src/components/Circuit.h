#pragma once

#include "Node.h"
#include <vector>
#include <stack>

class Circuit
{
    
    double total_current_;
    std::stack<Node*> circuit_nodes_;
    Node *entry_node_;

    Node* find_last_node_();
    Node* find_last_node_(Node* node);
    int traverse();
    int traverse(Node* node);

    public:
    Circuit(Node *entry_node);
    double total_current();
    Node *entry_node();
    void add_node_series(Node* node);
    void display_circuit();
};