class Solution
{
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    
public:
    void insertHeap(int &x)
    {
        if (leftHeap.empty() || x <= leftHeap.top())
            leftHeap.push(x);
        else
            rightHeap.push(x);
        
        balanceHeaps();
    }
    void balanceHeaps()
    {
        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    double getMedian()
    {
        if (leftHeap.size() == rightHeap.size()) {
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        } else {
            return leftHeap.top();
        }
    }
};