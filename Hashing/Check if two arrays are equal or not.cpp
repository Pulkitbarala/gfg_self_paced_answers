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