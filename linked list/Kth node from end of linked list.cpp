class Solution {
public:
    int getKthFromLast(Node *head, int k) {
        Node *first = head;
        Node *second = head;

        for (int i = 0; i < k; i++) {
            if (first == NULL) return -1; 
            first = first->next;
        }

        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        return second->data;
    }
};