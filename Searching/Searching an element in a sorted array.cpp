class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    for (int i = 0; i < N; ++i) {
            if (arr[i] == K) {
                return 1;
            }
        }
        return -1;
       
    }
};