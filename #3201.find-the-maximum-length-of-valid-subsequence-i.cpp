class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int even = 0;
        int odd = 0;
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }

            if (nums[i] % 2 != nums[i + 1] % 2) {
                ans++;
            }
        }
        
        if (nums[nums.size() - 1] % 2 == 0) {
            even++;
        } else {
            odd++;
        }

        return max(ans, max(even, odd));
    }
};
