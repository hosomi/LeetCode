class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int size = nums.size();
        vector<int> work;
        vector<vector<int>> result;    
        for (int i = 0; i < 1 << size; ++i) {
            work.clear();
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    work.push_back(nums[j]);
                }
            }
            result.push_back(work);
        }
        return result;
    }
};
