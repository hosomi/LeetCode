class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmostK(nums, k) - atmostK(nums, k-1);
    }

private:
    int atmostK(vector<int>& nums, int k) {

        int i = 0;
        int j = 0;
        unordered_map<int, int> um;
        int size = nums.size();
        int result = 0;
        while (i < size) {

            if (k >= 0) {
                ++um[nums[i]];
                if (um[nums[i]] == 1) {
                    --k;
                }
                ++i;
            }

            while (k < 0) {
                --um[nums[j]];
                if (um[nums[j]] == 0) {
                    ++k;
                }
                ++j;
            }
            result += i - j + 1;
        }
        return result;
    }
};
