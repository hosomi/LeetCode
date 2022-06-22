class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int size = weights.size();
        int low = *std::max_element(weights.begin() ,weights.end());
        long long int sum = 0;
        for (int i = 0; i < size; i++) {
            sum+=weights[i];
        }

        while(low < sum) {
            int mid = low + (sum - low) / 2;
            int totalDays = 1;
            int capacity = 0;
            for (int i = 0; i < size; i++) {
                if ((capacity + weights[i]) > mid) {
                    totalDays++;
                    capacity = weights[i];
                } else {
                    capacity += weights[i];
                }
            }
            
            if (totalDays <= days) {
                sum = mid;
            } else {
                low = mid+1;
            }
        }
        return sum;
    }
};
