class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        int i = 0;
        int j = 0;
        int result = nums.size()+1;
        int curr = 0;
        vector<int> arr(32, 0);
        while (i < nums.size()) {
            curr = curr | nums[i];
            for (int k = 0; k < 32; k++) {
                if ((nums[i] & (1<<k)) > 0) {
                    arr[k]++;
                }
            }

            while (j <= i && curr >= k) {
                result = std::min(i-j+1, result);
                for (int k = 0; k < 32; k++) {
                    if ((nums[j] & (1 << k)) > 0) {
                        arr[k]--;
                    }
                    if (arr[k] == 0) {
                        curr = curr & (~(1 << k));
                    }
                }
                j++;
            }
            i++;
        }
        return result > nums.size() ? -1 : result;
    }
};
