class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int size = grid.size();
        map<vector<int>,int> m;
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < size; j++) {
                temp.push_back(grid[i][j]);
            }
            m[temp]++;
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < size; j++) {
                temp.push_back(grid[j][i]);
            }

            if (m.find(temp) != m.end()) {
                result += m[temp];
            }
        }
        return result;
    }
};
