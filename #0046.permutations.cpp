class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        const int size = nums.size();
        vector<vector<int>> result;
        vector<int> vnums(size);
        vector<int> vwork;

        function<void(int)> backtrack = [&](int index) {
            if (index == size) {
                result.push_back(vwork);
                return;
            }

            for (int i = 0; i < size; ++i) {
                if (vnums[i]) {
                    continue;
                }
                vnums[i] = 1;
                vwork.push_back(nums[i]);
                backtrack(index + 1);
                vwork.pop_back();
                vnums[i] = 0;
            }
        };

        backtrack(0);
        return result;
    }
};
