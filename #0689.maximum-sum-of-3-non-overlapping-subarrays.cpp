class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n+1), right(n+1), left(n+1);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        auto sumk = [&](int start) {
            return prefix[start + k] - prefix[start];
        };

        left[0] = 0;
        for (int i = 1; i <= n - k; i++) {
            left[i] = sumk(i) > sumk(left[i - 1]) ? i : left[i - 1];
        }

        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            right[i] = sumk(i) >= sumk(right[i + 1]) ? i : right[i + 1];
        }

        vector<int> ret(3);
        int mxsum = 0, tmpsum;
        for (int i = k; i <= n - 2 * k; i++) {
            tmpsum = sumk(left[i - k]) + sumk(i) + sumk(right[i + k]);
            if (tmpsum > mxsum) {
                ret[0] = left[i - k];
                ret[1] = i;
                ret[2] = right[i + k];
                mxsum = tmpsum;
            }
        }
        return ret;
    }
};
