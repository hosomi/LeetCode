class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int size = nums.size();
        int max = 1;
        int min = 1;
        int result = INT_MIN;
        for (int i = 0; i < size; ++i) {
            if (nums[i] < 0) {
                std::swap(max, min);
            } 
            max = std::max(max * nums[i], nums[i]);
            min = std::min(min * nums[i], nums[i]);
            result = std::max(result, max);
        }
        return result;
    }
};
