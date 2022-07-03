class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int size = nums.size(); 
        if (size <= 1) {
            return size;
        }

        int left = 1;
        int right = 1; 
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                left = right + 1;
            }
            if (nums[i] < nums[i - 1]) {
                right = left + 1;
            }
        }
        
        return std::max(left, right); 
    }
};
