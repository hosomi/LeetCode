class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        int size = matchsticks.size();
        if (size < 4) {
            return false;
        }

        int sum = std::accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum % 4) {
            return false;
        }

        std::sort(matchsticks.rbegin(), matchsticks.rend());
        vector<bool> visited(size, false);
        return makesquare(matchsticks, visited, sum / 4, 0, 0, 0);
    }

private:
    bool makesquare(vector<int>& matchsticks, vector<bool>& visited,
                    int target, int curSide, int cnt, int idx) {

        if (cnt == 3) {
            return true;
        }

        if (target < curSide) {
            return false;
        }

        if (target == curSide) {
            return makesquare(matchsticks, visited, target, 0, cnt + 1, 0);
        }

        for (int i = idx; i < matchsticks.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            if (makesquare(matchsticks, visited, target,
                           curSide + matchsticks[i], cnt, i + 1)) {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
};
