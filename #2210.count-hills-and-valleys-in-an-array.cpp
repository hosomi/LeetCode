class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int count = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int left = nums[i - 1];
            while (nums[i] == nums[i+1] && i < nums.size() - 2) {
                i++;
            }
            
            int right = nums[i+1];
            if (nums[i] > left && nums[i] > right) {
                count++;
            } else if (nums[i] < left && nums[i] < right) {
                count++;
            }
        }
        return count;
    }
};
