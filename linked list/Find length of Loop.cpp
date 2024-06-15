int countNodesinLoop(struct Node *head)
{
    if (head == NULL || head->next == NULL) return 0;

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            Node *current = slow;
            while (current->next != slow) {
                count++;
                current = current->next;
            }
            return count;
        }
    }

    return 0;
}
