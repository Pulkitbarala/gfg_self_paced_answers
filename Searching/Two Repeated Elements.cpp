class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        vector<int> res(2);
        bool first = false;

        // iterating over the array elements.
        for (int i = 0; i < n + 2; i++) {
            // making the visited elements negative.
            if (arr[abs(arr[i])] > 0)
                arr[abs(arr[i])] = -arr[abs(arr[i])];

            // if the number is negative, it was visited previously
            // so this would be the repeated element.
            else {
                // storing first and second repeated element accordingly.
                if (first == false) {
                    res[0] = abs(arr[i]);
                    first = true;
                } else {
                    res[1] = abs(arr[i]);
                    break;
                }
            }
        }
        // returning the result.
        return res;
    }
};
