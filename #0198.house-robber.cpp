class Solution {
public:
    int rob(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return nums[0];
        }

        vector<int> v = nums;
        v.push_back(0);
        for(int i = size-3; i >= 0; i--) {
            v[i] += std::max(v[i+2], v[i+3]);
        }
        return std::max(v[0], v[1]);
    }
};
