int strstr(string s, string x) {
    int n = s.size();
    int m = x.size();

    // Loop through the main string
    for (int i = 0; i <= n - m; ++i) {
        int j;
        // Check if substring starting from i matches x
        for (j = 0; j < m; ++j) {
            if (s[i + j] != x[j]) {
                break;
            }
        }
        // If we matched all characters of x
        if (j == m) {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}