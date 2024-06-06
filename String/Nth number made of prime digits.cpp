class Solution {
public:
    // Function to find nth number made of only prime digits.
    int primeDigits(int n) {
        long long len = 1;
        long long prev_count = 0;

        // Find the length of the nth number
        while (true) {
            long long curr_count = prev_count + pow(4, len);
            if (prev_count < n && curr_count >= n)
                break;
            len++;
            prev_count = curr_count;
        }

        // Determine each digit at its respective place
        string result;
        for (int i = 1; i <= len; i++) {
            for (long long j = 1; j <= 4; j++) {
                if (prev_count + pow(4, len - i) < n)
                    prev_count += pow(4, len - i);
                else {
                    if (j == 1)
                        result += "2";
                    else if (j == 2)
                        result += "3";
                    else if (j == 3)
                        result += "5";
                    else if (j == 4)
                        result += "7";
                    break;
                }
            }
        }

        // Convert the string result to an integer and return it
        return stoi(result);
    }
};
