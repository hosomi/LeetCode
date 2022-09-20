class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>>v(size1 + 1, vector<int>(size2 + 1));
        int result = 0;
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    v[i][j] = v[i-1][j-1]+1;
                    result = std::max(result, v[i][j]);
                }
            }
        }
        return result;
    }
};
