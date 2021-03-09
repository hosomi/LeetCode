class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int size = nums.size();
        int work;
        for (int i = 0; i < size; i++) {
            while(nums[i] != i+1) {
                if (nums[i] <= 0 || nums[i] > size || nums[i] == nums[nums[i] -1]) {
                    break;
                }
                work = nums[i];
                nums[i] = nums[work-1];
                nums[work-1] = work;
            }  
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;  
    }
};
