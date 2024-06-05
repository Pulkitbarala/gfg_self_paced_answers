class Solution {
public:
    vector<string> winner(string arr[], int n) {
        map<string, int> votes;

        for (int i = 0; i < n; i++) {
            votes[arr[i]]++;
        }

        string winner = "";
        int maxVotes = 0;

        for (auto it = votes.begin(); it != votes.end(); it++) {
            if (it->second > maxVotes || (it->second == maxVotes && it->first < winner)) {
                winner = it->first;
                maxVotes = it->second;
            }
        }

        return {winner, to_string(maxVotes)};
    }
};
