class Solution {
public:
    Node* mergeKLists(Node* arr[], int K) {
        auto cmp = [](Node* a, Node* b) { return a->data > b->data; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> minHeap(cmp);
        
        for (int i = 0; i < K; ++i) {
            if (arr[i] != NULL) {
                minHeap.push(arr[i]);
            }
        }
        
        Node dummy(0);
        Node* tail = &dummy;
        
        while (!minHeap.empty()) {
            Node* minNode = minHeap.top();
            minHeap.pop();
            
            tail->next = minNode;
            tail = tail->next;
            
            if (minNode->next != NULL) {
                minHeap.push(minNode->next);
            }
        }
        
        return dummy.next;
    }
};