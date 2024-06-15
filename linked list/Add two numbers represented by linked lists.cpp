class Solution
{
    public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // Reverse both linked lists
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        Node* dummyHead = new Node(0); 
        Node* current = dummyHead;
        int carry = 0;
        
        while (num1 != NULL || num2 != NULL || carry != 0) {
            int sum = carry;
            if (num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            current->next = new Node(sum);
            current = current->next;
        }
        
        Node* result = reverseList(dummyHead->next);
        delete dummyHead;
        
        while (result != NULL && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }
        
        if (result == NULL) {
            result = new Node(0);
        }
        
        return result;
    }
};
