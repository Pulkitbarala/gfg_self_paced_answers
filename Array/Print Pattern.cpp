class Solution{
public:
    vector<int> pattern(int N){
        vector<int> result;
        if (N == 0) {
            result.push_back(0);
            return result;
        }
        helper(N, result, true, N);
        return result;
    }
    
    void helper(int N, vector<int>& result, bool decreasing, int initial){
        if ((N == initial && !decreasing) || (N == initial && initial < 0)) {
            result.push_back(N);
            return;
        }
        result.push_back(N);
        if (N > 0 && decreasing)
            helper(N - 5, result, decreasing, initial);
        else if (N < initial)
            helper(N + 5, result, false, initial);
        else
            helper(N - 5, result, true, initial);
    }
};
