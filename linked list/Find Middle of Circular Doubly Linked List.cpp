class Solution{
public:
    int findMiddle(Node * head)
    {
        if (head == NULL)
            return -1;

        Node *slow = head;
        Node *fast = head;

        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};
