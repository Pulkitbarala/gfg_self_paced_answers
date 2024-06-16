class Solution {
public:
    vector<int> maxOfMin(int arr[], int n) {
        vector<int> left(n, -1), right(n, n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }

        vector<int> windowSizes(n, 0);

        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            windowSizes[windowSize - 1] = max(windowSizes[windowSize - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            windowSizes[i] = max(windowSizes[i], windowSizes[i + 1]);
        }

        return windowSizes;
    }
};