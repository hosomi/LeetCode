class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        int n = nums.size();
        int cnt = 0;
        map<int, int> mp;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) {
                cnt++;
            }
            if( cnt % modulo == k) {
                ans++;
            }
            ans += mp[(cnt + modulo - k) % modulo];
            mp[(cnt) % modulo]++;
        }
        return ans;
    }
};
