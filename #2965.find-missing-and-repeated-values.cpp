class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        unordered_map<int, int> m;
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                m[grid[i][j]]++;
            }
        }

        int size = grid.size() * grid.size() + 1;
        vector<int> results = {0, 0};
        for (int i = 1; i < size; i++) {
            if (m[i] == 0) {
                results[1] = i;
            } else if (m[i] == 2) {
                results[0] = i;
            }
        }
        return results;
    }
};
