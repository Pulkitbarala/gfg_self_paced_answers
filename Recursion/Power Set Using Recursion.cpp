//User function Template for C++
vector<string> powerSet(string s) {
    vector<string> result;
    function<void(string, int)> backtrack = [&](string subset, int index) {
        result.push_back(subset);
        for (int i = index; i < s.size(); ++i) {
            backtrack(subset + s[i], i + 1);
        }
    };
    backtrack("", 0);

    return result;
}