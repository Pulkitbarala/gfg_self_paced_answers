class Solution
{
public:
    long long maximumSum(int arr[], int sizeOfArray)
    {
        long long max_so_far = arr[0];
        long long max_ending_here = arr[0];
        cout << max_ending_here << " ";
        for (int i = 1; i < sizeOfArray; ++i) {
            max_ending_here = max((long long)arr[i], max_ending_here + arr[i]);
            cout << max_ending_here << " ";
            max_so_far = max(max_so_far, max_ending_here);
        }
        cout << endl;
        return max_so_far;
    }
};