#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit(Node* entry_node)
{
    entry_node_ = entry_node;
    entry_node_->add_next(entry_node_);
    entry_node_->add_prev(entry_node_);
};

double Circuit::total_current()
{
    return total_current_;
};

Node* Circuit::entry_node()
{
    return entry_node_;
};

/**
 * @brief Find last node in the circuit. 
 * 
 * @details If a node branches to multiple, you don't need to track each node in the branch.
 * It's enough to pick one as whichever you pick has to lead to the same node eventually.
 * Therefore the algorithm chooses arbitratrily the first one in the unordered_map returned by node->next().
 * 
 * @return Node*. Return the last node in the circuit.
 */
Node* Circuit::find_last_node_()
{
    Node* node = entry_node_;
    if(node->next()[0] == entry_node_)
    {
        return node;
    }
    else
    {
        find_last_node_(node->next()[0]);
    }
    return NULL;
}

Node* Circuit::find_last_node_(Node* node)
{
    if(node->next()[0] == entry_node_)
    {
        return node;
    }
    else
    {
        find_last_node_(node->next()[0]);
    }
    return NULL;
}

void Circuit::add_node_series(Node* node)
{
    Node* last = find_last_node_();
    last->next().clear();
    last->next().push_back(node);
    node->prev().push_back(last);
    entry_node_->prev().clear();
    entry_node_->prev().push_back(node);
}

int Circuit::traverse()
{
    Node* node = entry_node_;
    cout << node->id() << endl;
    node->set_visited(true);
    if(node->next().size() > 1)
    {
        circuit_nodes_.push(node);
        for(auto tmp : node->next())
        {
            if(tmp->visited() == false)
            {
                traverse(tmp);
            }
        }
        circuit_nodes_.pop();

        if(circuit_nodes_.size() > 0)
        {
            Node* tmp = circuit_nodes_.top();
            circuit_nodes_.pop();
            traverse(tmp);  
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(node->next()[0] != entry_node_)
        {
            traverse(node->next()[0]);
        }
        else if(circuit_nodes_.size() != 0)
        {
            Node* tmp = circuit_nodes_.top();
            circuit_nodes_.pop();
            traverse(tmp);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int Circuit::traverse(Node* start_node)
{
    Node* node = start_node;
    cout << node->id() << endl;
    node->set_visited(true);
    if(node->next().size() > 1)
    {
        circuit_nodes_.push(node);
        for(auto tmp : node->next())
        {
            if(tmp->visited() == false)
            {
                traverse(tmp);
            }
        }
        circuit_nodes_.pop();

        if(circuit_nodes_.size() > 0)
        {
            Node* tmp = circuit_nodes_.top();
            circuit_nodes_.pop();
            traverse(tmp);  
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(node->next()[0] != entry_node_)
        {
            traverse(node->next()[0]);
        }
        else if(circuit_nodes_.size() != 0)
        {
            Node* tmp = circuit_nodes_.top();
            circuit_nodes_.pop();
            traverse(tmp);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void Circuit::display_circuit()
{
    traverse();
}