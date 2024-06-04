class Solution {
public:
    vector<int> twoRepeated(int arr[], int n) {
        vector<int> result;

        for (int i = 0; i < n + 2; i++) {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0) {
                result.push_back(abs(arr[i]));
            } else {
                arr[index] = -arr[index];
            }
            if (result.size() == 2) {
                break;
            }
        }

        return result;
    }
};