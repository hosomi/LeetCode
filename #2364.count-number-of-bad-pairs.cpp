class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        unordered_map<long long, long long> mp;
        long long res = 0;
        long long n = size(nums);
        long long total = n * (n - 1) / 2;
        for (int i = 0; i < size(nums); i++) {
            mp[nums[i] - i]++;
        }
        for (auto &[k,v] : mp) {
            if(v > 1) {
                res += v * (v - 1) / 2;
            }
        }
 
        return total-res;
    }
};
