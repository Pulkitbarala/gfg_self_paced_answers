class Solution{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        unordered_set<int> elements;
        for (int i = 0; i < N; i++) {
            elements.insert(arr[i]);
        }
        
        int longestStreak = 0;
        for (int i = 0; i < N; i++) {
            if (elements.find(arr[i] - 1) == elements.end()) {
                int currentNum = arr[i];
                int currentStreak = 1;
                while (elements.find(currentNum + 1) != elements.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};