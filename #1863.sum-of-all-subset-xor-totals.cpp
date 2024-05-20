class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int sum = 0;
        for (auto& num : nums){
            sum |= num;
        }

        return sum << (nums.size() - 1);
    }
};
