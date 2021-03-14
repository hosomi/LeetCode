class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int size = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        vector<int> used(size);
        vector<int> v;
        depthFirstSearch(size, nums, v, used, result);
        return result;
    }

private:
    void depthFirstSearch(const int size, const vector<int>& nums,
                          vector<int>& v, vector<int>& used, vector<vector<int>>& result) {

        if (v.size() == size) {
            result.push_back(v);
            return;
        }

        for (int i = 0; i < size; ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = 1;
            v.push_back(nums[i]);
            depthFirstSearch(size, nums, v, used, result);
            v.pop_back();
            used[i] = 0;
        }
    }
};
