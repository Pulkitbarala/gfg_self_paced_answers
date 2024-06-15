struct Node* pairwise_swap(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        current = current->next->next;
    }

    return head;
}