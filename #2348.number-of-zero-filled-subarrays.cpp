class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int size = nums.size();
        long long count = 0;
        long long result = 0;
        for (int i = 0; i < size; i++) {
            count = nums[i] == 0 ? count + 1 : 0;
            result += count;
        }
        return result;
    }
};
