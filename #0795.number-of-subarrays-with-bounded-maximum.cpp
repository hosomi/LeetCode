class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        return count(nums, right) - count(nums, left - 1);
    }

private:
    int count(vector<int>&nums, int index) {

        int result = 0;
        int count = 0;
        for (auto &num : nums) {
            count = num <= index ? ++count : 0;
            result += count;
        }
        return result;
    }
};
