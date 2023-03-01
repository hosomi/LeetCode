class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        
        int l = 1;
        int result = INT_MIN;
        for (int i = 1; i < size; i++) {
            if (nums[i] - nums[i-1] <= 0) {
                result = std::max(result, l);
                l = 1;
            } else {
                l++;
            }
        }
        result = std::max(result, l);
        return result;
    }
};
