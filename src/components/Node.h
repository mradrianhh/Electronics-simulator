#pragma once

class Node
{
    protected:

    inline static int s_count_;
    int id_;
    
    public:
    Node();
    int id();
};