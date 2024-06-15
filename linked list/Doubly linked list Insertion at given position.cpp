void addNode(Node *head, int pos, int data)
{
    Node* current = head;
    for(int i = 0; i < pos; i++) {
        if(current != NULL)
            current = current->next;
    }

    Node* newNode = new Node(data);

    newNode->next = current->next;
    newNode->prev = current;

    if(current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
}
