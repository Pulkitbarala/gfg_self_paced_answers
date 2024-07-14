class Solution
{
    public:
    int kMostFrequent(int arr[], int n, int k) 
    { 
        unordered_map<int, int> freqMap;
        for (int i = 0; i < n; ++i) {
            freqMap[arr[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& pair : freqMap) {
            minHeap.push(pair.second);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        int sum = 0;
        while (!minHeap.empty()) {
            sum += minHeap.top();
            minHeap.pop();
        }

        return sum;
    } 
};
