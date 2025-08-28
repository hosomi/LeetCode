class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> dia;
            int row = i, col = 0;
            while (row < n && col < n) {
                dia.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(dia.rbegin(), dia.rend()); 
            row = i;
            col = 0;
            int index = 0;
            while (row < n && col < n) {
                grid[row][col] = dia[index++];
                row++;
                col++;
            }
        }

        for (int j = 1; j < n; j++) {
            vector<int> dia;
            int row = 0, col = j;
            while (row < n && col < n) {
                dia.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(dia.begin(), dia.end()); 
            row = 0;
            col = j;
            int index = 0;
            while (row < n && col < n && index < dia.size()) {
                grid[row][col] = dia[index++];
                row++;
                col++;
            }
        }
        return grid;
    }
};
