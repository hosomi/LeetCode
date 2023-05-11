class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int size = nums.size();
        bool isIncreasing = true;
        bool isDecreasing = true;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i + 1] - nums[i] < 0) {
                isIncreasing = false;
            }

            if (nums[i + 1] - nums[i] > 0) {
                isDecreasing = false;
            }
            
            if (!isIncreasing && !isDecreasing) {
                return false;
            }
        }
        return isIncreasing || isDecreasing;
    }
};
