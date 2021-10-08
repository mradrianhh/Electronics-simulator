#include "Loop.h"
#include <iostream>

using namespace std;

Loop::Loop(Node* entry_node)
{
    entry_node_ = entry_node;
    entry_node_->set_next(entry_node_);
    entry_node_->set_prev(entry_node_);
};

double Loop::total_current()
{
    return total_current_;
};

Node* Loop::entry_node()
{
    return entry_node_;
};

Node* Loop::find_last_node()
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

void Loop::add_node(Node* node)
{
    Node* last = find_last_node();
    last->set_next(node);
    node->set_prev(last);
    node->set_next(entry_node_);
    entry_node_->set_prev(node);
}

void Loop::display_nodes()
{
    Node* tmp = entry_node_;
    do
    {
        cout << tmp->id() << " - " << tmp->name() << endl;
        tmp = tmp->next();
    } while (tmp->id() != entry_node_->id());
    
}