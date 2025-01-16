class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int l1 = nums1.size();
        int res = 0;
        if (l1 & 1) {
            for (int n: nums2) {
                res ^= n;
            }
        }

        int l2 = nums2.size();
        if (l2 & 1) {
            for (int n: nums1) {
                res ^= n;
            }
        }
        return res;
    }
};
