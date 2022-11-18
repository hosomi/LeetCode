class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> result;
        for (int num_ : nums) {
            int num = std::abs(num_);
            nums[num - 1] *= -1;
            if (nums[num - 1] > 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};
