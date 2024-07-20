void makeDoubly(struct Node* head) {
    struct Node* prev_node = NULL;
    struct Node* curr_node = head;
    while (curr_node != NULL) {
        curr_node->prev = prev_node;
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}
