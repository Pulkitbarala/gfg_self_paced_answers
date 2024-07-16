class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> activities;
        for(int i = 0; i < n; i++) {
            activities.push_back({end[i], start[i]});
        }
        sort(activities.begin(), activities.end());
        
        int count = 0;
        int lastEndTime = -1;
        for(int i = 0; i < n; i++) {
            if(activities[i].second > lastEndTime) {
                count++;
                lastEndTime = activities[i].first;
            }
        }
        
        return count;
    }
};