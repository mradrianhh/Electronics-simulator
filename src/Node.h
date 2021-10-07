class Node
{
    static int s_count_;
    int id_;
    double voltage_drop_; // if positive, it's a voltage gain.

    public:
    Node(double voltage_drop);
    int id();
    double voltage_drop();
    void set_voltage_drop(double voltage_drop);
}