class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> v1;
        for (int x : s1) {
            if (!s2.count(x)) {
                v1.push_back(x);
            }
        }

        vector<int> v2;
        for (int x : s2) {
            if (!s1.count(x)) {
                v2.push_back(x);
            }
        }
        return {v1, v2};
    }
};
