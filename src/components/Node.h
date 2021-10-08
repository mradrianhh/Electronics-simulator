#pragma once

#include <string>

class Node
{
    protected:

    inline static int s_count_;
    int id_;
    std::string name_;
    Node * next_; // Series implementation first. For parallell, it can have multiple nodes next.
    Node * prev_; // Needs memory of previous node for analysis.

    public:
    Node();
    Node(std::string name);
    int id();
    Node * next();
    void set_next(Node* node);
    Node * prev();
    void set_prev(Node* node);
    std::string name();
    void set_name(std::string name);
};