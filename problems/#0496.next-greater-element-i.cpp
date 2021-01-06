class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cache;
        vector<int> greater;

        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums2[i]) {
                    cache[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (cache.count(nums1[i])) {
                greater.push_back(cache[nums1[i]]);
            } else {
                greater.push_back(-1);
            }
        }
        return greater;
    }
};
