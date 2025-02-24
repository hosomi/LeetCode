class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        size = edges.size();
        for (auto & e : edges) {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        return dfs(0, 0, -1, bob, amount).first;
    }

private:
    unordered_map<int, unordered_set<int>> m;
    int size = 0;

    pair<int, int> dfs(int n, int d0, int p, int bob, vector<int>& amount) {

        int db = n == bob ? 0 : size, res = n == bob ? 0 : amount[n];
        int leaf = 1;
        for (int nxt : m[n]) {
            if (nxt == p) {
                continue;
            }

            auto [r, d] = dfs(nxt, d0+1, n, bob, amount);
            db = std::min(d, db);
            res = leaf == 1 ? r : std::max(res, r);
            leaf = 0;
        }

        if (!leaf && d0 < db) {
            res += amount[n];
        }
        if (!leaf && d0 == db) {
            res += amount[n] / 2;
        }

        return {res, db + 1};
    }
};
