class Solution
{
public:
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };

    vector<int> mergeKArrays(vector<vector<int>>& arr, int K)
    {
        vector<int> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> minHeap;
        for (int i = 0; i < K; ++i) {
            minHeap.push({arr[i][0], {i, 0}});
        }

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int value = top.first;
            int row = top.second.first;
            int col = top.second.second;
            result.push_back(value);
            if (col + 1 < K) {
                minHeap.push({arr[row][col + 1], {row, col + 1}});
            }
        }

        return result;
    }
};
