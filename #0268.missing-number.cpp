class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int size = nums.size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            result ^= nums[i];
            result ^= i;
        }
        return result ^= size;
    }
};
