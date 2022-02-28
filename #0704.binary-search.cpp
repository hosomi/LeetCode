class Solution {
public:
    int search(vector<int>& nums, int target) {

        return bSearch(nums, target, 0, nums.size() - 1);
    }

private:
    int bSearch(vector<int>& nums, int target, int start, int end) {

        if (end < start) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        
        if (target < nums[mid]) {
            return bSearch(nums, target, start, mid - 1);
        }
        
        return bSearch(nums, target, mid + 1, end);
    }
};
