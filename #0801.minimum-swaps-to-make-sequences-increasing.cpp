class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int size = nums1.size();
        vector<int> swap1(size, 0);
        vector<int> swap2(size, 1);
        for (int i = 1; i < size; i++) {
            swap1[i] = swap2[i] = size;
            
            if (nums1[i-1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                swap1[i] = swap1[i - 1];
                swap2[i] = swap2[i - 1] + 1;
            }

            if (nums1[i-1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                swap1[i] = std::min(swap1[i], swap2[i - 1]);
                swap2[i] = std::min(swap2[i], swap1[i - 1] + 1);
            }
        }
        return std::min(swap1[size - 1], swap2[size - 1]);
    }
};
