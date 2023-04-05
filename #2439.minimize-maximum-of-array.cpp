class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int size = nums.size();
        long sum = 0;
        long result = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            result = std::max(result, (sum + i) / (i + 1));
        }
        return result;
    }
};
