class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        constexpr std::array<int, 5> directions = {0, 1, 0, -1, 0};
        auto dfs = [&](auto &&self, int i, int j, int islandID) -> int {
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
                return 0;
            }
            grid[i][j] = islandID;
            int area = 1;
            
            for (int d = 0; d < 4; ++d) {
                int nextI = i + directions[d];
                int nextJ = j + directions[d + 1];
                area += self(self, nextI, nextJ, islandID);
            }

            return area;
        };

        int islandID = 2;
        std::unordered_map<int, int> islandsArea;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = dfs(dfs, i, j, islandID);
                    islandsArea[islandID] = area;
                    ++islandID;
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }

                std::unordered_set<int> visitedIslands;
                int totalArea = 1;
                for (int d = 0; d < 4; ++d) {
                    int nextI = i + directions[d];
                    int nextJ = j + directions[d + 1];
                    if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n) {
                        continue;
                    }
                    if (int islandID = grid[nextI][nextJ]; islandID > 1 && !visitedIslands.count(islandID)) {
                        totalArea += islandsArea[islandID];
                        visitedIslands.insert(islandID);
                    }
                }
                maxArea = std::max(maxArea, totalArea);
            }
        }
        return maxArea == 0 ? n * n : maxArea;
    }
};
