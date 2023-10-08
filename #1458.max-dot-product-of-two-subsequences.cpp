class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>> max(size1 + 1,
            vector<int>(size2 + 1, INT_MIN));
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                max[i][j] = std::max(
                    std::max(max[i - 1][j - 1], 0)
                    + nums1[i - 1] * nums2[j - 1],
                    std::max(max[i - 1][j], max[i][j - 1])
                );
            }
        }
        return max[size1][size2];
    }
};
