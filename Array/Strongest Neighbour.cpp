void maximumAdjacent(int sizeOfArray, int arr[]){
    for (int i = 0; i < sizeOfArray - 1; i++) {
        cout << max(arr[i], arr[i + 1]) << " ";
    }
}