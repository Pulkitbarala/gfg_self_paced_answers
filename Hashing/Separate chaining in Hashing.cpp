class Solution{
  public:
    vector<vector<int>> separateChaining(int hashSize, int arr[], int sizeOfArray) {
        vector<vector<int>> hashTable(hashSize);

        for (int i = 0; i < sizeOfArray; i++) {
            int key = arr[i];
            int hashIndex = key % hashSize;
            hashTable[hashIndex].push_back(key);
        }

        return hashTable;
    }
};