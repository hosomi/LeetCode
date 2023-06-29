class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int sx;
        int sy;
        map<char,int> mkey;
        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x][y] == '@') {
                    sx = x;
                    sy = y;
                } else if ('a' <= grid[x][y] && grid[x][y] <= 'z') {
                    mkey[grid[x][y]] = 1;
                }
            }
        }

        int k = 0;
        for (auto &a : mkey) {
            a.second = k++;
        }

        int ans = (1<<k) - 1;
        map<tuple<int,int,int>,int> visited;
        queue<tuple<int,int,int>> q;
        q.push({ sx, sy, 0 });
        visited[{ sx, sy, 0 }] = 1;
        while (q.size()) {
            auto [xx,yy,key] = q.front();
            q.pop();

            if (key == ans) {
                return visited[{ xx, yy, key }] - 1;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx= xx + dirx[dir];
                int ny = yy + diry[dir];
                int nkey = key;
                if (nx >= 0 && nx < row &&
                    ny >= 0 && ny < col &&
                    grid[nx][ny] != '#') {
                    if (mkey.find(grid[nx][ny]) != mkey.end()) {
                        nkey|=(1<<mkey[grid[nx][ny]]);
                    }

                    if ('A' <= grid[nx][ny] && grid[nx][ny]<='Z') {
                        int lock = mkey[grid[nx][ny] - 'A' + 'a'];
                        if (((nkey>>lock)&1) == 0) {
                            continue;
                        }
                    }

                    tuple<int,int,int> nstate = { nx, ny, nkey };
                    if (visited[nstate] > 0) {
                        continue;
                    }

                    visited[nstate] = visited[{xx, yy, key}] + 1;
                    q.push(nstate);
                }
            }
        }
        return -1;
    }

private:
    int dirx[4] = { 1, 0, -1, 0 };
    int diry[4] = { 0, 1, 0, -1 };
};
