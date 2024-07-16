class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<double, int>> ratio(n);
        for (int i = 0; i < n; i++) {
            ratio[i] = {(double)arr[i].value / arr[i].weight, i};
        }
        sort(ratio.rbegin(), ratio.rend());
        
        double maxValue = 0.0;
        int currentWeight = 0;
        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if (currentWeight + arr[idx].weight <= W) {
                currentWeight += arr[idx].weight;
                maxValue += arr[idx].value;
            } else {
                int remainingWeight = W - currentWeight;
                maxValue += arr[idx].value * ((double)remainingWeight / arr[idx].weight);
                break;
            }
        }
        
        return maxValue;
    }
};