class Solution {
public:
    string rearrangeString(string str) {
        unordered_map<char, int> freqMap;
        for (char c : str) {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        string result = "";
        pair<int, char> prev(-1, '#');

        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.second;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            current.first--;
            prev = current;
        }

        if (result.length() == str.length()) {
            return result;
        }

        return "-1";
    }
};