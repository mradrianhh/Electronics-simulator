#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit(Node* entry_node)
{
    entry_node_ = entry_node;
    entry_node_->set_next(entry_node_);
    entry_node_->set_prev(entry_node_);
};

double Circuit::total_current()
{
    return total_current_;
};

Node* Circuit::entry_node()
{
    return entry_node_;
};

Node* Circuit::find_last_node()
{
    Node* tmp = entry_node_;
    CHECK_LAST:
    if(tmp->next()->id() == entry_node_->id())
    {
        return tmp;
    }
    else
    {
        tmp = tmp->next();
        goto CHECK_LAST;
    }
}

void Circuit::add_node(Node* node)
{
    Node* last = find_last_node();
    last->set_next(node);
    node->set_prev(last);
    node->set_next(entry_node_);
    entry_node_->set_prev(node);
}

void Circuit::display_nodes()
{
    Node* tmp = entry_node_;
    do
    {
        cout << tmp->id() << " - " << tmp->name() << endl;
        tmp = tmp->next();
    } while (tmp->id() != entry_node_->id());
    
}