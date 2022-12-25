class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int size = nums.size();
        vector<int> v;
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < size; i++) {
            nums[i] += nums[i - 1];
        }

        for (auto &q : queries) {
            int upper_bound = std::upper_bound(nums.begin(), nums.end(), q)
                - nums.begin();
            v.push_back(upper_bound);
        }
        return v;
    }
};
