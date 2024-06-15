class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        struct Node* prev = NULL;
        struct Node* current = head;
        struct Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};
