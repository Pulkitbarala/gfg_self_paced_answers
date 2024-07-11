#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countSmallerElements(const vector<int>& arr) {
    set<int> seen;
    int maxCount = 0;

    for (int i = arr.size() - 1; i >= 0; --i) {
        seen.insert(arr[i]);
        auto it = seen.lower_bound(arr[i]);
        int count = distance(seen.begin(), it);
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        cout << countSmallerElements(arr) << endl;
    }
    return 0;
}
