class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = size - 1;
        int count = 0;
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                count++;
                i++;
                j--;
            } else if (nums[i] + nums[j] > k) {
                j--;
            } else {
                i++;
            }
        }
        return count;
    }
};
