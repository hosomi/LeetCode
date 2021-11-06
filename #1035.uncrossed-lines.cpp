class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int nums1size = nums1.size();
        int nums2size = nums2.size();
        vector<vector<int>> result(nums1size + 1, vector(nums2size + 1, 0));
        for (int i = 1; i <= nums1size; i++) {
            for (int j = 1; j <= nums2size; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    result[i][j] = result[i - 1][j - 1] + 1;
                } else {
                    result[i][j] = std::max(result[i][j - 1], result[i - 1][j]);
                }
            }
        }
        return result[nums1size][nums2size];
    }
};
