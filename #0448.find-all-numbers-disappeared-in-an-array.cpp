class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int num = std::abs(nums[i]) - 1;
            if(nums[num] > 0){
                nums[num] *= -1;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
