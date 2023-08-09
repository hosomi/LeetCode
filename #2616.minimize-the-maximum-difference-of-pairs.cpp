class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        
        long long low = 0;
        long long high = 1e10;
        long long mid;
        while (low < high) {
            mid = (low + high) / 2;
            vector<int> dp(size);
            dp[0] = 0;
            dp[1] = (nums[1]-nums[0]) <= mid;
            
            for (int i=2; i < size; i++) {
                dp[i] = std::max(((nums[i] - nums[i-1]) <= mid)
                    + dp[i-2], dp[i-1]);
            }
            
            if (dp[size - 1] >= p) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
