class Solution
{
public:
    int kthSmallest(int arr[], int n, int k)
    {
        priority_queue<int> maxHeap(arr, arr + k);
        for (int i = k; i < n; ++i) {
            if (arr[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        return maxHeap.top();
    }
};