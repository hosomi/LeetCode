class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int size = nums.size();
        int result = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = size - 1; i >= 0; i--) {
            int low= 0;
            int high = i - 1;
            while (low <= high) {
                if (nums[low] + nums[high] > nums[i]) {
                    result += high - low;
                    high--;
                } else {
                    low++;
                }
            }
        }
        return result;
    }
};
