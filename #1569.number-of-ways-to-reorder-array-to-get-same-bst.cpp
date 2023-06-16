class Solution {
public:
    int numOfWays(vector<int>& nums) {
        
        bst(nums.size()); 
        return dfs(nums) - 1;
    }

private:
    long long MOD = 1e9+7;
    vector<vector<int>> ways;
    
    void bst(int max_num){
        ways = vector<vector<int>>(max_num+1);
        
        for (int i = 0; i <= max_num; ++i){
            ways[i] = vector<int>(i + 1);
            ways[i][0] = ways[i][i] = 1;
            for(int j = 1; j < i; ++j){
                ways[i][j] =
                    (ways[i - 1][j - 1] + ways[i - 1][j]) % MOD;
            }
        }
    }
    
    int dfs(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 1;
        }
        
        vector<int> left, right;
        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        long long left_res = dfs(left);
        long long right_res = dfs(right);
        return ((ways[size - 1][left.size()] * left_res) % MOD * right_res) % MOD;
    }
};
