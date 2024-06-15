class Solution{
public:
    bool isCircular(Node *head)
    {
        if (head == NULL) 
            return false;

        Node *current = head;

        while (current->next != NULL && current->next != head) {
            current = current->next;
        }

        return (current->next == head);
    }
};
