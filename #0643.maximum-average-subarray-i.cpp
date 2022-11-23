class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double ksum = 0;
        for (int i = 0; i < k; i++) {
            ksum += nums[i];
        }
        
        int size = nums.size();
        double sum = ksum;
        for (int i = 1; i <= size - k; i++) {
            ksum = ksum - nums[i - 1] + nums[i + k - 1];
            sum = std::max(sum, ksum);
        }
        return sum / k;
    }
};
