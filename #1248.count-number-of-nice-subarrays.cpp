class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int j = 0;
        int count = 0;
        int sum = 0;
        unordered_map<int, int> m;
        while (j < nums.size()) {
            if (nums[j]%2 != 0) {
                sum += 1;
            }

            if (sum == k) {
                count++;
            }

            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }

            m[sum]++;
            j++;
        }
        return count;
    }
};
