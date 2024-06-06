class Solution
{
    public:
    // Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        // Count the number of 1s in the string
        long count1 = 0;
        for(char ch : a) {
            if(ch == '1') {
                count1++;
            }
        }
        // Using the formula count1 * (count1 - 1) / 2 to find the number of substrings
        return (count1 * (count1 - 1)) / 2;
    }
};