class Solution{
    public:
    long long countPairs(int X[], int Y[], int M, int N) {
        sort(Y, Y + N);
        
        vector<int> countY(1001, 0);
        for (int i = 0; i < N; i++) {
            countY[Y[i]]++;
        }
        
        auto countGreaterThanY = [&](int y) -> int {
            return N - (upper_bound(Y, Y + N, y) - Y);
        };
        
        long long result = 0;
        
        for (int i = 0; i < M; i++) {
            int x = X[i];
            if (x == 0) continue;
            if (x == 1) {
                result += countY[0];
                continue;
            }
            result += countGreaterThanY(x);
            result += countY[1];
            if (x == 2) {
                result -= countY[3];
                result -= countY[4];
            }
            if (x == 3) {
                result += countY[2];
            }
        }
        
        return result;
    }
};
//updated
