class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> m;
        for (auto num : nums1) {
            m[num] = 10;
        }

        for (auto num : nums2) {
            m[num]++;
            if (m[num] == 11) {
                return num;
            }
        }
        return -1;
    }
};
