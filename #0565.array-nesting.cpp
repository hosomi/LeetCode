class Solution {
public:
    int arrayNesting(vector<int>& nums) {

        int size = nums.size();
        int result = -1;
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0) {
                continue;
            }
            result = std::max(result, this->arrayNesting(nums, i));
        }
        return result;
    }

private:

    int arrayNesting(vector<int>& nums, int index) {

        if (index==-1) {
            return -1;
        }
        
        int num = nums[index];
        nums[index]=-1;
        return this->arrayNesting(nums, num) + 1;        
    }
};
