class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int size = nums.size();
        if (size <= 1) {
            return 0;
        }
        
        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        int start = -1;
        for (int i = 0; i < size; ++i) {
			if (nums[i] != sorted[i]) {
                start = i;
                break;
            }
        }

        if (start == -1) {
            return 0;
        }
        
        int end = -1;
        for (int i = size - 1; i >= 0; --i) {
			if (nums[i] != sorted[i]) {
                end = i;
                break;
            }
        }
        return end - start + 1;
    }
};
