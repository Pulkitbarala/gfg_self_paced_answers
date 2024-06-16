class Solution {
public:
    long long getMaxArea(long long arr[], int n) {
        stack<int> s;
        long long max_area = 0;
        int tp;
        long long area_with_top;

        int i = 0;
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]) {
                s.push(i++);
            } else {
                tp = s.top();
                s.pop();
                area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < area_with_top) {
                    max_area = area_with_top;
                }
            }
        }

        while (!s.empty()) {
            tp = s.top();
            s.pop();
            area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top) {
                max_area = area_with_top;
            }
        }

        return max_area;
    }
};