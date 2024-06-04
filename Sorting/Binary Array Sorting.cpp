class Solution{
  public:
    void binSort(int A[], int N)
    {
        int countZero = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == 0) {
                countZero++;
            }
        }
        for (int i = 0; i < countZero; i++) {
            A[i] = 0;
        }
        for (int i = countZero; i < N; i++) {
            A[i] = 1;
        }
    }
};