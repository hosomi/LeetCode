class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int size = nums.size();
        if (size < 2) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int result = 0;
        for(int i = 1; i < size; ++i){
            result = std::max(result, nums[i] - nums[i - 1]);
        }
        return result;
    }
};
