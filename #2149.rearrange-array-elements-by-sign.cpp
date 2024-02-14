class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int size = nums.size();
        int i1 = 0;
        int i2 = 1;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                result[i1] = nums[i];
                i1 += 2;
            } else {
                result[i2] = nums[i];
                i2 += 2;
            }
        }
        return result;
    }
};
