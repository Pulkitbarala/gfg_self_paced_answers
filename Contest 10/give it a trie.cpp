string LCP(string arr[], int n) {
    if (n == 0) return "";
    string prefix = arr[0];
    
    for (int i = 1; i < n; i++) {
        while (arr[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    
    return prefix;
}