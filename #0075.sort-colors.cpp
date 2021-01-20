class Solution {
public:
    void sortColors(vector<int>& nums) {

        int index = 0;
        int size = nums.size();
        for (int i = 0; i < 3; i++) {
            for (int j = index; j < size; j++) {
                if (nums[j] == i) {
                    swap(nums[j], nums[index]);
                    index++;
                }
            }
        }
    }
};
