class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b) {
        int low = 0, high = array.size() - 1;
        for (int i = 0; i <= high;) {
            if (array[i] < a) {
                swap(array[i], array[low]);
                ++low;
                ++i;
            } else if (array[i] > b) {
                swap(array[i], array[high]);
                --high;
            } else {
                ++i;
            }
        }
    }
};
