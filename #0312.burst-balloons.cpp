class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int size = nums.size();
        vector<vector<int>> result(size, vector<int>(size, 0));
        for (int i = 1; i <= size-2; i++) {
            for (int j = 0; j + i + 1 < size; j++) {
                int col = j + i + 1;
                for (int k = j + 1; k <= col - 1; k++) {
                    result[j][col] = std::max(result[j][col],
                        nums[j]*nums[k]*nums[col] +
                        result[j][k] +
                        result[k][col]);
                }
            }
        }
        return result[0][size-1];
    }
};
