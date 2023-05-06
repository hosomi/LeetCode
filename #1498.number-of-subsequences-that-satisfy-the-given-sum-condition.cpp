class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        int size = nums.size();
        int mod = 1e9+7;
        vector<int> v(size, 1);
        for (int i = 1; i < size; ++i) {
            v[i] = (v[i-1] << 1) % mod;
        }
        
        std::sort(nums.begin(), nums.end());
        int result = 0;
        for (int l = 0, r = size - 1; l <= r;) {
            if (nums[l] + nums[r] > target) {
                --r;
            } else {
                result = (result + v[r - l]) % mod;
                ++l;
            }
        }
        return result;   
    }
};
