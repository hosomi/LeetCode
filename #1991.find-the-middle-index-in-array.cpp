class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
    
        int size = nums.size();
        int num = 0;
        for (int i = 0; i < size; num += nums[i++]) {
            if (nums[i] == sum - 2 * num) {
                return i;
            }
        }
        return -1;
    }
};
