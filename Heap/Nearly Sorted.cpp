class Solution
{
    public:
    vector<int> nearlySorted(int arr[], int num, int K){
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> result;
        for(int i = 0; i <= K && i < num; i++) {
            minHeap.push(arr[i]);
        }
        for(int i = K + 1; i < num; i++) {
            result.push_back(minHeap.top());
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
