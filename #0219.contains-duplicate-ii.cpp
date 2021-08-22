class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int size = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < size; ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                return true;
            } else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
