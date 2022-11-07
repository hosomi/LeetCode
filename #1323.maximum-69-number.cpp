class Solution {
public:
    int maximum69Number (int num) {

        vector<int> nums;
        while(num) {
            nums.insert(nums.begin(), num % 10);
            num /= 10;
        }
        
        int size = nums.size();
        bool converted = false;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 9 && !converted) {
                nums[i] = 9;
                converted = true;
            }
            result = result * 10 + nums[i];
        }
        
        return result;
    }
};
