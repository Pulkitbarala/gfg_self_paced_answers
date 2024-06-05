int sumExists(int arr[], int N, int sum) {
    unordered_set<int> seen;

    for (int i = 0; i < N; i++) {
        int complement = sum - arr[i];

        if (seen.find(complement) != seen.end()) {
            return 1;
        }

        seen.insert(arr[i]);
    }

    return 0;
}