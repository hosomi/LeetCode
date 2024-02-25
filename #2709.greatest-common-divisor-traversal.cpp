class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {

        int size = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        int count = 0;
        g.assign(3 * max + 1,vector<int>());
        vis.assign(3 * max + 1, 0);
        for (auto it : nums) {
            while (it % 2 == 0) {
                g[size + 2].push_back(count);
                g[count].push_back(size + 2);
                it = it / 2;
            }

            for (int i = 3; i <= sqrt(it); i = i + 2) {
                while (it % i == 0) {
                    g[size + i].push_back(count);
                    g[count].push_back(size + i);
                    it = it/i;
                }
            }

            if (it > 2) {
                g[size + it].push_back(count);
                g[count].push_back(size + it);
            }
            count++;
        }

        dfs(0, -1);
        for (int i = 0; i < size; i++) {
            if (vis[i] == 0) {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<int>> g;
    vector<int> vis;
    void dfs (int u, int par) {
        vis[u] = 1;
        for (auto v : g[u]) {
            if (v == par) {
                continue;
            }

            if (vis[v] == 0) {
                dfs(v, u);
            }
        }
    }
};
