class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                return -1;
            }
        }

        set<int> s(nums.begin(), nums.end());

        int ans = s.size();
        for (int i : s) {
            if (i == k) {
                ans--;
            }
        }
        return ans;
    }
};
