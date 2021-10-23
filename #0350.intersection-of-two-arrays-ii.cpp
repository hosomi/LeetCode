class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> result;
        int num1 = 0;
        int num2 = 0;
        int num1size = nums1.size();
        int num2size = nums2.size();
        while (num1 < num1size && num2 < num2size) {
            if (nums1[num1] == nums2[num2]) {
                result.push_back(nums1[num1]);
                num1++;
                num2++;
            } else if(nums1[num1] < nums2[num2]) {
                num1++;
            } else {
                num2++;
            }
        }
        return result;
    }
};
