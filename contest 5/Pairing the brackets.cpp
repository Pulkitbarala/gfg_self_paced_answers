vector<pair<int, int>> pairingBrackets(string s) {
    queue<int> openingIndices;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            openingIndices.push(i);
        } else if (s[i] == ')' && !openingIndices.empty()) {
            int opening_index = openingIndices.front();
            openingIndices.pop();
            pairs.push_back({opening_index, i});
        }
    }

    return pairs;
}
