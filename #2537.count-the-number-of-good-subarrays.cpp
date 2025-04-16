class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long i = 0;
        long long j = 0;
        long long ans = 0;
        long long n = nums.size();
        unordered_map<int, int> mp;
        for (; j < n; j++) {
            k -= mp[nums[j]]++;
            while (k <= 0) {
                k+= --mp[nums[i++]];
            }
            ans += i;
        }
        return ans;
    }
};
