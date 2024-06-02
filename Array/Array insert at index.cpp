class Solution{
  public:
   void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
{
    for (int i = sizeOfArray - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}
};