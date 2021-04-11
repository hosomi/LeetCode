class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        vector<int> backtrack(k, 0);
        int index = 0;
        while (index >= 0) {
            ++backtrack[index];
            if (backtrack[index] > n) {
                --index;
            } else if (index == k - 1) {
                result.push_back(backtrack);
            } else {
                ++index;
                backtrack[index] = backtrack[index - 1];
            }
        }
        return result;
    }
};
