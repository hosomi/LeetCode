class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int size = nums.size(); 
        int i = 0;
        int j = 0;
        for(; i < size; i++){
            if(nums[i]){
                nums[j++] = nums[i];
            }
        }
        for(; j < size; j++){
            nums[j] = 0;
        }
    }
};
