Node *removeDuplicates(Node *head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* nextNode = current->next->next;
            delete(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
    return head;
}