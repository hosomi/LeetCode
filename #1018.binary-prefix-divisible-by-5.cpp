class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int size = nums.size();
        int num = 0;
        vector<bool> result(size);
        for (int i = 0; i < size; i++) {
            num = ((num << 1) + nums[i]) % 5;
            if (num == 0) {
                result[i] = true;
            }
        }
        return result;
    }
};
