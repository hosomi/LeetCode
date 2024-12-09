class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 && nums[i + 1] % 2) {
                s.insert(i);
            }

            if (nums[i] %2 == 0 && nums[i + 1] % 2 == 0) {
                s.insert(i);
            }
        }

        vector<bool>results;
        for (auto q : queries) {
            int start = q[0];
            int end = q[1];
            auto it = s.lower_bound(start);
            if (start == end || it == s.end() or *it >= end) {
                results.push_back(true);
            } else {
                results.push_back(false);
            }
        }
        return results;
    }
};
