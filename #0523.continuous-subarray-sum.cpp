class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int size = nums.size();
        if (size == 1) {
            return false;
        }

        unordered_map<int,int> m;
        int sum[size];
        sum[0] = nums[0];
        m[sum[0] % k] = 0;
        for (int i = 1; i < size; i++) {
            sum[i] = (sum[i - 1] + nums[i]);
            if (sum[i] % k == 0) {
                return true;
            }
            
            if (m.count(sum[i] % k) && m[sum[i] % k] < i - 1) {
                return true;
            }
            
            if (!m.count(sum[i] % k)) {
                m[sum[i] % k] = i;
            }
        }
        return false;
    }
};
