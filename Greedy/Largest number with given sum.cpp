class Solution
{
    public:
    string largestNumber(int n, int sum)
    {
        if (sum > 9 * n) return "-1";
        string result = "";
        
        for (int i = 0; i < n; i++) {
            if (sum >= 9) {
                result += '9';
                sum -= 9;
            } else {
                result += (sum + '0');
                sum = 0;
            }
        }
        
        return result;
    }
};
