class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            int low = i + 1;
            int high = size - 1;
            while (low < high) {
                int cursum = nums[i] + nums[low] +nums[high];
                if (cursum > target) {
                    high--;
                } else {
                    low++;
                }

                if (abs(cursum - target) < abs(result - target)) {
                    result = cursum;
                }
            }
        }
        return result;
    }
};
