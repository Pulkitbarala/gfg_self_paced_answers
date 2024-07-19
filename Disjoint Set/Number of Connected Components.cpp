class Solution
{
public:
    int find(int x, int arr[]) {
        if (arr[x] != x) {
            arr[x] = find(arr[x], arr);
        }
        return arr[x];
    }
    void unionNodes(int a, int b, int arr[], int rank1[], int n) {
        int rootA = find(a, arr);
        int rootB = find(b, arr);

        if (rootA != rootB) {
            if (rank1[rootA] > rank1[rootB]) {
                arr[rootB] = rootA;
            } else if (rank1[rootA] < rank1[rootB]) {
                arr[rootA] = rootB;
            } else {
                arr[rootB] = rootA;
                rank1[rootA]++;
            }
        }
    }
    int findNumberOfConnectedComponents(int n, int arr[], int rank1[]) {
        unordered_set<int> uniqueRoots;
        for (int i = 1; i <= n; ++i) {
            uniqueRoots.insert(find(i, arr));
        }
        return uniqueRoots.size();
    }
};
