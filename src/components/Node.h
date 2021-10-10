#pragma once

#include <string>
#include <vector>

class Node
{
    protected:

    inline static int s_count_;
    int id_;
    std::string name_;
    std::vector<Node*> next_; // For parallell, it can have multiple nodes next.
    std::vector<Node*> prev_; // Needs memory of previous node(s) for analysis.
    bool visited_; // To mark if node has been visited when traversing.

    public:
    Node();
    Node(std::string name);
    int id();
    std::vector<Node*> next();
    void add_next(Node* node);
    std::vector<Node*> prev();
    void add_prev(Node* node);
    std::string name();
    void set_name(std::string name);
    bool operator==(const Node& node);
    bool visited();
    void set_visited(bool visited);
};