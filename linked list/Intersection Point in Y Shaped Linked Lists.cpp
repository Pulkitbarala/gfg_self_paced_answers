int intersectPoint(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) return -1;

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    int len1 = 0, len2 = 0;

    while (ptr1 != NULL) {
        len1++;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        len2++;
        ptr2 = ptr2->next;
    }

    ptr1 = head1;
    ptr2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) {
            ptr1 = ptr1->next;
        }
    } else {
        int diff = len2 - len1;
        while (diff--) {
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}