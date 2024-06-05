class Solution{
  public:
    void QuadraticProbing(vector<int>& hash, int hashSize, int arr[], int N) {
        for (int i = 0; i < N; i++) {
            int key = arr[i];
            int hashIndex = key % hashSize;
            int originalIndex = hashIndex;
            int j = 0;
            while (hash[hashIndex] != -1) {
                j++;
                hashIndex = (originalIndex + j * j) % hashSize;
            }
            hash[hashIndex] = key;
        }
    }
};