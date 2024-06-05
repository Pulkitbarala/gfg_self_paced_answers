class Solution{
    public:
    void sortABS(int A[], int N, int k)
    {
        stable_sort(A, A + N, [k](int a, int b) {
            return abs(a - k) < abs(b - k);
        });
    }
};
