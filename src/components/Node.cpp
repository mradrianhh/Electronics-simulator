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

std::vector<Node*> Node::next()
{
    return next_;
};

void Node::add_next(Node* node)
{
    next_.push_back(node);
};

std::vector<Node*> Node::prev()
{
    return prev_;
};

void Node::add_prev(Node* node)
{
    prev_.push_back(node);
};

std::string Node::name()
{
    return name_;
};

void Node::set_name(std::string name)
{
    name_ = name;
}

bool Node::visited()
{
    return visited_;
}

void Node::set_visited(bool visited)
{
    visited_ = visited;
}

bool Node::operator==(const Node& node)
{
    if(this->id() == node.id_)
    {
        return true;
    }
    else
    {
        return false;
    }
};