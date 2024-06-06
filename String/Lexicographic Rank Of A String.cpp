class Solution {
  public:
    // Function to find lexicographic rank of a string.
    int findRank(string S) {
        int MOD = 1000000007;
        int n = S.length();
        int rank = 1;
        
        // Factorial of n
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = (fact * i) % MOD;
        }
        
        // Map to store count of each character
        unordered_map<char, int> count;
        for (char c : S) {
            count[c]++;
        }
        
        // Calculate rank
        for (int i = 0; i < n; i++) {
            fact = (fact * (n - i)) % MOD;
            int mul = 1;
            for (auto it = count.begin(); it != count.end(); it++) {
                if (it->first < S[i]) {
                    rank = (rank + (fact * it->second) % MOD * mul) % MOD;
                }
                mul = (mul * it->second) % MOD;
            }
            count[S[i]]--;
        }
        
        return rank;
    }
};