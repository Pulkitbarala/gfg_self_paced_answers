class Solution {
public:
    void enqueue(queue<int> &q, int x) {
        q.push(x);
    }
     
    void dequeue(queue<int> &q) {
        if (!q.empty()) {
            q.pop();
        }
    }
    
    int front(queue<int> &q) {
        if (!q.empty()) {
            return q.front();
        }
        return -1;
    }
    
    string find(queue<int> q, int x) {
        while (!q.empty()) {
            if (q.front() == x) {
                return "Yes";
            }
            q.pop();
        }
        return "No";
    }
};
