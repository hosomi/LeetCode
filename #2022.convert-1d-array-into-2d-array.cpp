class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if (original.size() != m * n) {
            return {};
        }

        int it = 0;
        vector<vector<int>> results;
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(original[it++]);
            }
            results.push_back(temp);
        }
        return results;
    }
};
