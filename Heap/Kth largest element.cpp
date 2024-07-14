class Solution
{
    public:
    int KthLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < k; i++) {
            minHeap.push(arr[i]);
        }
        for (int i = k; i < n; i++) {
            if (arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
        return minHeap.top();
    }
};
