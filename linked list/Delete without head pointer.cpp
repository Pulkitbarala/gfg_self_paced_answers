class Solution
{
    public:
    void deleteNode(Node *del_node)
    {
        if (del_node == NULL || del_node->next == NULL)
            return;
        
        Node *next_node = del_node->next;
        del_node->data = next_node->data;
        
        del_node->next = next_node->next;
        
        delete next_node;
    }
};