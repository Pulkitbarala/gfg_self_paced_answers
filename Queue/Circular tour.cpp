class Solution {
public:
    int tour(petrolPump p[], int n) {
        int start = 0;
        int total_surplus = 0;
        int current_surplus = 0;
        
        for (int i = 0; i < n; ++i) {
            int surplus = p[i].petrol - p[i].distance;
            total_surplus += surplus;
            current_surplus += surplus;
            
            if (current_surplus < 0) {
                start = i + 1;
                current_surplus = 0;
            }
        }
        
        return (total_surplus >= 0) ? start : -1;
    }
};