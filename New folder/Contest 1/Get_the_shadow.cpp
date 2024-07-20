class Solution {
public:
    vector<int> solve(int N, vector<int>& a) {
        vector<int> result;
        int i = 0;

        while (i < N) {
            if (a[i] != a[a[i] - 1]) {
                swap(a[a[i] - 1], a[i]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (a[i] != i + 1) {
                result.push_back(a[i]);
                result.push_back(i + 1);
                break;
            }
        }

        return result;
    }
};
