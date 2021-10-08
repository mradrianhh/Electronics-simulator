#include "Node.h"

Node::Node()
{
    s_count_++;
    id_ = s_count_;
}

int Node::id()
{
    return id_;
}