struct st_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {


        unordered_map<std::pair<int, int>, bool, st_hash> mp;
        for (int i = 0; i < obstacles.size(); i++) {
            mp[make_pair(obstacles[i][0], obstacles[i][1])] = true;
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        int result = 0;
        for (int cmd: commands) {
            if (cmd == -2) {
                di = (di + 3) % 4;
                continue;
            }

            if (cmd == -1) {
                di = (di + 1) % 4;
                continue;
            }

            for (int k = 0; k < cmd; ++k) {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (!mp[make_pair(nx,ny)]) {
                    x = nx;
                    y = ny;
                    result = std::max(result, x * x + y * y);
                } else {
                    break;
                }
            }
        }
        return result;
    }
};

