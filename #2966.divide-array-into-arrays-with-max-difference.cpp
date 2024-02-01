class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        std::sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i+=3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }

            v.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return v;
    }
};
