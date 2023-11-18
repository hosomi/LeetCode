class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int size = nums.size();
        long long j = 0;
        long long max = 0;
        long long sum = 0;
        std::sort(nums.begin(), nums.end());
        for (long long i = 0; i < size; ++i) {
            sum += nums[i];
            while (((i - j + 1) * nums[i]) - sum > k) {
                sum -= nums[j];
                j++;
            }
            max = std::max(max, i - j + 1);
        }
        return max;
    }
};
