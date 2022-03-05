class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int size = nums.size();
        int max = *std::max_element(nums.begin(), nums.end());
        vector<int> num(max + 1);
        for (int i = 0; i < size; i++) {
            num[nums[i]] += nums[i];
        }

        vector<int> result(max + 1, 0);
        result[1] = num[1];
        for (int i = 2; i <= max; i++) {
            result[i] = std::max(result[i - 1], result[i - 2] + num[i]);
        }
        return result[max];
    }
};
