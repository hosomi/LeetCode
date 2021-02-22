class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }
        
        int size = nums.size();
        int index = 0;
        for (int i = 1; i < size; i++) {
            if(nums[i] != nums[index]){
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};
