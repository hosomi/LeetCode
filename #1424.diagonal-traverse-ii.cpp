class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int size = nums.size();
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> results;
        while (!q.empty()) {
            auto [row,col] = q.front();
            q.pop();
            results.push_back(nums[row][col]);

            if (col == 0 && row + 1 < size) {
                q.push({row+1, col});
            }
            if (col + 1 < nums[row].size()) {
                q.push({row, col + 1});
            }
        }
        return results;
    }
};
