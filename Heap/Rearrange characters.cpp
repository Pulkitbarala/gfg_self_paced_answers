class Solution
{
public:
    string rearrangeString(string str)
    {
        unordered_map<char, int> freq;
        for (char c : str)
        {
            freq[c]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for (auto it : freq)
        {
            maxHeap.push({it.second, it.first});
        }

        // Resultant string
        string result = "";
        pair<int, char> prev = {-1, '#'};

        while (!maxHeap.empty())
        {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.second;

            if (prev.first > 0)
            {
                maxHeap.push(prev);
            }

            current.first--;
            prev = current;
        }
        return (result.length() == str.length()) ? result : "0";
    }
};
