class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int result = 0;
        for (int num : nums) {
            sum = (sum + num) % k;
            if (sum < 0) {
                sum += k;
            }
            result += m[sum]++;
        }
        return result;
    }
};
