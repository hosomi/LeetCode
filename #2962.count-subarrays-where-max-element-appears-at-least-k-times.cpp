class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int max = *max_element(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] == max) {
                k--;
            }

            while (k == 0) {
                if (nums[i++] == max) {
                    k++;
                }
            }
            result += i;
        }
        return result;
    }
};
