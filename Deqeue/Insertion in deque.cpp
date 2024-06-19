class Solution {
  public:
    deque<int> deque_Init(int arr[], int n) {
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            dq.push_back(arr[i]);
        }
        return dq;
    }
};