class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int i = 0;
        int j = n - 1;
        vector<int> ans(n, pivot);
        while (i < n) {
            if (nums[i] < pivot) {
                ans[lo++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[hi--] = nums[j];
            }
            i++;
            j--;
        };
        return ans;
    }
};
