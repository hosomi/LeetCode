class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int size = nums.size();
        int accumulate = std::accumulate(nums.begin(),
            nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (sum * 2 == accumulate - nums[i]) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
