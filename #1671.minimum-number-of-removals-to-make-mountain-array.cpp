class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int size = nums.size();
        vector<int> v(size, 0);
        vector<int> v2(size, 0);
        for (int i = 1; i <size; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[i]>nums[j]) {
                    v[i]=max(v[i],v[j]+1);
                }
            }
        }

        for (int i = size - 2; i >= 0; i--) {
            for (int j = size - 1; j > i; j--) {
                if (nums[i]>nums[j]) {
                    v2[i] = std::max(v2[i], v2[j] + 1);
                }
            }
        }

        int result = INT_MAX;
        for (int i = 1; i < size-1; i++) {
            if (v[i] == 0 || v2[i] == 0) {
                continue;
            }

            result = std::min( result, (i-v[i])+(size-i-1-v2[i]));
        }
        return result;
    }
};
