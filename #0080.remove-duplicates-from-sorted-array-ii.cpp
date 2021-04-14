class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();
        int index = 0;
        for (int i = 0; i < size; ++i) {
            if (index < 2 || nums[i] != nums[index - 2]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
