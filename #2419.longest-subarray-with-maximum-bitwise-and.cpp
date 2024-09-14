class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (i < n && nums[i] == max) {
                cnt++;
                i++;
            }
            result = std::max(result, cnt);
        }
        return result;
    }
};
