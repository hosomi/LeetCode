class Solution {
public:
    int findMaxK(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int>m;
        for (auto num : nums) {
            m[num]++;
        }

        int result = -1;
        for (int i = 0; i < n; i++) {
            if (m.find(-nums[i]) != m.end()) {
                result = std::max(result, nums[i]);
            }
        }
        return result;
    }
};
