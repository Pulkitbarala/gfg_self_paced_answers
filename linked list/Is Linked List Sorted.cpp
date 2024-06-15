bool isSorted(Node * head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *current = head;
    bool nonDecreasing = true;
    bool nonIncreasing = true;

    while (current->next != NULL) {
        if (current->data > current->next->data)
            nonDecreasing = false;
        if (current->data < current->next->data)
            nonIncreasing = false;
        current = current->next;
    }

    return nonDecreasing || nonIncreasing;
}