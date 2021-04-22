class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int mindex = m - 1;
        int nindex = n - 1;
        int index = m + n - 1;
        while (nindex >= 0) {
            nums1[index--] = mindex >= 0 && nums1[mindex] > nums2[nindex]
                ? nums1[mindex--] : nums2[nindex--];
        }
    }
};
