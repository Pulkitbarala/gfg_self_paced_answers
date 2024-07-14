class Solution
{
    public:
    void kthLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < n; ++i)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(arr[i]);
                if (minHeap.size() < k)
                    cout << "-1 ";
                else
                    cout << minHeap.top() << " ";
            }
            else
            {
                if (arr[i] > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
                cout << minHeap.top() << " ";
            }
        }
    }
};