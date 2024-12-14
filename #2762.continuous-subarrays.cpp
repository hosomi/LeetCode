class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        long long n = nums.size();
        long long i = 0;
        map<int, int> m;
        long long result = 0;
        for (int j = 0; j < n; j++) {
            m[nums[j]]++;
            while (i < j && m.rbegin() -> first - m.begin() -> first > 2) {
                if (!--m[nums[i]]) {
                    m.erase(nums[i]);
                }
                i++;
            }
            result += j - i + 1;
        }
        return result;
    }
};
