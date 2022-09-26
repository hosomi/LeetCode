class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int size = nums.size();
        vector<vector<int>> v(2, vector(2001, 0));
        v[(size - 1) % 2][nums[size - 1] + 1000] = 1;
        v[(size - 1) % 2][-nums[size - 1] + 1000] += 1;
        for (int i = size - 2; i >= 0; i--) {
            for (int j = -1000; j <= 1000; j++){
                if(v[(i + 1) % 2][j + 1000] > 0){
                    v[i % 2][j + nums[i] + 1000] += v[(i + 1) % 2][j + 1000];
                    v[i % 2][j - nums[i] + 1000] += v[(i + 1) % 2][j + 1000];
                }
                v[(i + 1) % 2][j + 1000] = 0;
            }
        }
        return (target <= 1000) ? v[0][target + 1000] : 0;
    }
};
