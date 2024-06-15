class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (!head) return NULL;

        Node* temp = head;

        if (x == 1) {
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return head;
        }

        for (int i = 1; temp != NULL && i < x; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return head;

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
        return head;
    }
};