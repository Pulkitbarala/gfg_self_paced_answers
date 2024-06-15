class Solution{
public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node *prev = NULL, *current = slow, *next;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        Node *firstHalf = head, *secondHalf = prev;
        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};