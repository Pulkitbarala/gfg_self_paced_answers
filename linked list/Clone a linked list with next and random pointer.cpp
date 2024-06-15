class Solution {
public:
    Node* copyList(Node *head) {
        if (!head) return NULL;

        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = next;
            curr = next;
        }

        curr = head;
        while (curr) {
            if (curr->arb)
                curr->next->arb = curr->arb->next;
            curr = curr->next->next;
        }

        Node* copyHead = head->next;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }

        return copyHead;
    }
};