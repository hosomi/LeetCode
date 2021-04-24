class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        int index = 0;
        int size;
        vector<int> v;
        vector<vector<int>> result(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            if (!i || nums[i] != nums[i - 1]) {
                index = 0;
            }
            size = result.size();
            for (int j = size; index < j; index++) {
                v = result[index];
                v.push_back(nums[i]);
                result.push_back(v);
            }
        }
        return result;
    }
};
