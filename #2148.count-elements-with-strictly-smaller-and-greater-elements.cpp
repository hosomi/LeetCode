class Solution {
public:
    int countElements(vector<int>& nums) {
        
        int max = *std::max_element(nums.begin(), nums.end());
        int min = *std::min_element(nums.begin(), nums.end());
        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] > min && nums[i] < max) {
                count++;
            }
        }
        return count;
    }
};
