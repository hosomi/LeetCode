class Solution {
public:
    int minCapability(vector<int>& nums, int k) {

        int lo = 0;
        int hi = 1e9;
        while (hi - lo > 1) {
            int mid = (long long)(hi + lo) / 2;
            if (valid(mid, nums, k)){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }

private:
    int valid(int mid,vector<int> &nums,int k) {

        int cn =0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= mid) {
                cn++;
                i++;
            }
        }
        return cn >= k;
    }
};
