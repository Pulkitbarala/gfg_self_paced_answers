class Solution
{
    public:
    int getCount(struct Node* head){
        int count = 0;
        struct Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
};
