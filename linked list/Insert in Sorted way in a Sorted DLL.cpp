Node* sortedInsert(Node *head, int x) {
    Node* newNode = getNode(x);

    if (head == NULL) {
        return newNode;
    }

    if (x < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* current = head;

    while (current->next != NULL && current->next->data < x) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return head;
};