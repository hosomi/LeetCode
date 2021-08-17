class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> cursor;
        int sum;
        for (int i = 0; i < (1 << 9); ++i) {
            cursor = {};
            sum = 0;
            for (int j = 1; j <= 9; ++j) {
                if (i & (1 << (j - 1))) {
                    sum += j;
                    cursor.push_back(j);
                }
            }

            if (sum == n && cursor.size() == k) {
                result.push_back(cursor);
            }
        }
        return result;
    }
};
