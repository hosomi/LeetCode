class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> us(nums.begin(), nums.end());
        int result = 0;
        int length;
        for (int num : nums) {
            if (!us.count(num - 1)) {
                length = 0;
                while (us.count(num++)) {
                    ++length;
                }
                result = std::max(result, length);
            }
        }
        return result;
    }
};
