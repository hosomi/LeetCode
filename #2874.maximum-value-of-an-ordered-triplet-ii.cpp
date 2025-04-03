class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        long long maxdiff = 0;
        long long maxnum = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = std::max(res, maxdiff * nums[i]);
            maxdiff = std::max(maxdiff, maxnum - nums[i]);
            maxnum = std::max(maxnum, (long long) nums[i]);
        }
        return res;
    }
};
