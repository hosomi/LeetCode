class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        int size = nums.size();
        int i = 0;
        long num = 0;
        int result = 0;
        while (num < n) {
            if (i < size) {
                if (nums[i] <= num + 1) {
                    num += nums[i];
                    i++;
                } else {
                    result++;
                    num += num + 1;
                }
            } else {
                result ++;
                num += num + 1;
            }
        }
        return result;
    }
};
