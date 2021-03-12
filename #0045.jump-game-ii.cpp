class Solution {
public:
    int jump(vector<int>& nums) {

        int size = nums.size() - 1;
        int result = 0;
        int index = 0;
        int max = 0; 
        for (int i = 0; i < size; i++) {
            max = std::max(max, nums[i] + i); 
            if (i == index){ 
                index = max;
                result++;
            }
        }
        return result;
    }
};
