#include "Node.h"

Node::Node()
{
    s_count_++;
    id_ = s_count_;
}

Node::Node(std::string name)
{
    s_count_++;
    id_ = s_count_;
    name_ = name;
}

int Node::id()
{
    return id_;
}

Node * Node::next()
{
    return next_;
};

void Node::set_next(Node* node)
{
    next_ = node;
};

Node * Node::prev()
{
    return prev_;
};

void Node::set_prev(Node* node)
{
    prev_ = node;
};

std::string Node::name()
{
    return name_;
};

void Node::set_name(std::string name)
{
    name_ = name;
}