class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long cnt = 0;
        long long leftSum = 0;
        long long rightSum = 0;
        for (auto num : nums) {
            rightSum += num;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum) {
                cnt++;
            }
        }
        return cnt;
    }
};
