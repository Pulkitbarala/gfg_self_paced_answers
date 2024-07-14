class Solution {
public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (long long i = 0; i < n; i++) {
            minHeap.push(arr[i]);
        }
        
        long long totalCost = 0;
        while (minHeap.size() > 1) {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            
            long long combined = first + second;
            totalCost += combined;
            minHeap.push(combined);
        }
        
        return totalCost;
    }
};
