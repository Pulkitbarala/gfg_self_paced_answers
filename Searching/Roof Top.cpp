class Solution
{
    public:
    int maxStep(int A[], int N)
{
    int maxSteps = 0;
    int currSteps = 0;
    
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1]) {
            currSteps++;
            maxSteps = max(maxSteps, currSteps);
        } else {
            currSteps = 0;
        }
    }
    
    return maxSteps;
}

};
-------------------------------------------------------------------------
class Solution {
  public:
    int maxStep(vector<int> arr) {
        int max_steps = 0;
        int current_steps = 0;
        
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                current_steps++;
            } else {
                max_steps = max(max_steps, current_steps);
                current_steps = 0;
            }
        }
        
        max_steps = max(max_steps, current_steps);
        return max_steps;
    }
};
