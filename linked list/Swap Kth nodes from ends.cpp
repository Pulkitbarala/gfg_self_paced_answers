Node *swapkthnode(Node* head, int num, int K)
{
    if (K > num) return head;
    if (2 * K - 1 == num) return head;
    
    Node *x_prev = NULL;
    Node *x = head;
    for (int i = 1; i < K; i++) {
        x_prev = x;
        x = x->next;
    }
    
    Node *y_prev = NULL;
    Node *y = head;
    for (int i = 1; i < num - K + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    
    if (x_prev)
        x_prev->next = y;
    
    if (y_prev)
        y_prev->next = x;
    
    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    if (K == 1)
        head = y;
    if (K == num)
        head = x;
    
    return head;
}