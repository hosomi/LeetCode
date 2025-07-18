class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n = nums.size() / 3;
        priority_queue<int> added;
        vector<long long> leftN(2 * n);
        long long sum = 0;
        for (int i=0;i<2*n;i++) {
            sum += nums[i];
            added.push(nums[i]);
            if (added.size() > n) {
                sum -= added.top();
                added.pop();
            }

            if (added.size() == n) {
                leftN[i] = sum;
            }
        }

        priority_queue<int, vector<int>, greater<int>> rightAdd;
        sum = 0;
        long long ans = LONG_LONG_MAX;
        for (int i = nums.size() - 1; i >= n; i--) {
            sum += nums[i];
            rightAdd.push(nums[i]);
            if (rightAdd.size() > n) {
                sum -= rightAdd.top();
                rightAdd.pop();
            }

            if (rightAdd.size()==n) {
                ans = min(ans,leftN[i-1] - sum);
            }
        }
        return ans;
    }
};
