class Solution {
public:
    // Function to calculate sum of all numbers present in a string.
    int findSum(string str) {
        int sum = 0;
        int i = 0;

        while (i < str.size()) {
            // Skip non-digit characters
            while (i < str.size() && !isdigit(str[i])) {
                i++;
            }

            // Initialize the start index of the number
            int start = i;

            // Scan the digits to find the end of the number
            while (i < str.size() && isdigit(str[i])) {
                i++;
            }

            // Convert the scanned substring to an integer and add it to the sum
            if (start != i) {
                sum += stoi(str.substr(start, i - start));
            }
        }

        return sum;
    }
};