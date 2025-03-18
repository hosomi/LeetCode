class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = size(nums);
        int start = 0;
        int end = 0;
        int bitmask = 0;
        int ans = 0;
        while (end < n) {
            while ((bitmask & nums[end]) != 0){
                bitmask^=nums[start++]; 
            }
            bitmask |= nums[end];
            ans = std::max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};
