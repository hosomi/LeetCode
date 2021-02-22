class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        
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
