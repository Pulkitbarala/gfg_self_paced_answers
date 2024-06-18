int kthMaximumElement(int arr[], int n, int k)
{
    priority_queue<int> maxHeap(arr, arr + n);
    
    for(int i = 1; i < k; i++) {
        maxHeap.pop();
    }
    return maxHeap.top();
}