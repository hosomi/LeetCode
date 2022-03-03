class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int size = nums.size();
        int count = 0;
        int result = 0;
        for (int i = 2; i < size; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                count++;
            } else {
                result += (count+1) * count / 2;
                count = 0;
            }
        }
        return (result += (count + 1) * count / 2);
    }
};
