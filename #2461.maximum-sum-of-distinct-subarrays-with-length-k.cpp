class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int ,int> m;
        long long i = 0;
        long long s = 0;
        long long result = 0;
        for (int j = 0; j < nums.size(); j++) {
            m[nums[j]]++;
            s += nums[j];
            if (!(k == j - i + 1)) {
                continue;
            }

            if (m.size() == k) {
                result = std::max(result, s);
            }
            s -= nums[i];
            m[nums[i]]--;
            if (!m[nums[i]]) {
                m.erase(nums[i]);
            }
            i++;
        }
        return result;
    }
};
