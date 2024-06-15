Node * joinTheLists(Node * head1, Node * head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = head2;
    return head1;
}