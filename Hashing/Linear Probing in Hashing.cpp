class Solution{
  public:
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray) {
        vector<int> hashTable(hashSize, -1);

        for (int i = 0; i < sizeOfArray; i++) {
            int key = arr[i];
            int hashIndex = key % hashSize;
            int startIndex = hashIndex;
            while (hashTable[hashIndex] != -1 && hashTable[hashIndex] != key) {
                hashIndex = (hashIndex + 1) % hashSize;
                if (hashIndex == startIndex) break;
            }
            if (hashTable[hashIndex] == -1) {
                hashTable[hashIndex] = key;
            }
        }

        return hashTable;
    }
};