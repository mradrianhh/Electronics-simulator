#pragma once

#include "Node.h"

class Loop
{
    
    double total_current_;
    Node *entry_node_;

    public:
    Loop(Node *entry_node);
    double total_current();
    Node *entry_node();
    void add_node(Node* node);
    Node* find_last_node();
    void display_nodes();
};