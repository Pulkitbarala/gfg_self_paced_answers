class Solution
{
    public:
    string mostFrequentWord(string arr[], int n) 
    {
        unordered_map<string, int> frequency;
        unordered_map<string, int> firstOccurrence;
        for (int i = 0; i < n; ++i) {
            string word = arr[i];
            if (frequency.find(word) == frequency.end()) {
                firstOccurrence[word] = i; 
            }
            frequency[word]++;
        }
        string mostFrequent;
        int maxFreq = 0;
        int latestIndex = -1;
        for (const auto& entry : frequency) {
            const string& word = entry.first;
            int freq = entry.second;

            if (freq > maxFreq || (freq == maxFreq && firstOccurrence[word] > latestIndex)) {
                maxFreq = freq;
                mostFrequent = word;
                latestIndex = firstOccurrence[word];
            }
        }

        return mostFrequent;
    }
};