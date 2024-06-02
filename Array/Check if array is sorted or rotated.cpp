
class Solution {
public:
    bool checkRotatedAndSorted(int arr[], int num) {
        int incBreaks = 0;
        int decBreaks = 0;

        for (int i = 0; i < num; i++) {
            if (arr[i] > arr[(i + 1) % num]) {
                incBreaks++;
            }
        }

        for (int i = 0; i < num; i++) {
            if (arr[i] < arr[(i + 1) % num]) {
                decBreaks++;
            }
        }

        return (incBreaks == 1 || decBreaks == 1);
    }
};