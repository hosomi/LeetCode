class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

	    for (int i(0);
            i < size(nums);
            nums[i++] = (i ? nums[i-1] : 0)
            + (1 + nums[i] + (i ? nums[i-1] : 0)
            - (i >= k ? nums[i - k] : 0)) % 2);                        
	    return nums.back() > nums[size(nums) - k] ? - 1 : nums[size(nums) - k];
    }
};
