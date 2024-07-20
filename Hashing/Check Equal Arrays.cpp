class Solution{
    public:
    bool check(vector<ll> A, vector<ll> B, int N) {
        unordered_map<ll, int> countA, countB;

        for (int i = 0; i < N; i++) {
            countA[A[i]]++;
            countB[B[i]]++;
        }
        return countA == countB;
    }
};
-----------------------------------------------------------------------------------
class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() != arr2.size()) {
            return false;
        }
        
        unordered_map<int, int> count1, count2;
        
        for (int num : arr1) {
            count1[num]++;
        }
        
        for (int num : arr2) {
            count2[num]++;
        }
        
        return count1 == count2;
    }
};
