class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int row = maze.size();
        int col = maze[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<pair<pair<int,int>, int>>q;
        q.push({{entrance[0], entrance[1]}, 0});
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            maze[x][y]='+';
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (((x1 == 0 || x1 == row - 1) && (y1 >= 0 && y1 < col))
                    || ((y1 == 0 || y1 == col - 1) && (x1>=0 && x1<row))) {

                    if (maze[x1][y1] == '.') {
                        return d + 1;
                    }
                }

                if (x1 >= 0 && x1 < row && y1 >= 0 && y1 < col && maze[x1][y1] == '.' ) {
                    maze[x1][y1] = '+';
                    q.push({{x1, y1}, d + 1});
                }
            }
        }
        return-1;
    }
};
