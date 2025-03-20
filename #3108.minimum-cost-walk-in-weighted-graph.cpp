class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        int m = edges.size();
        map<pair<int,int>, int> mp;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (mp.find({std::min(u, v), std::max(u, v)}) == mp.end()) {
                mp[{std::min(u, v), std::max(u, v)}] = w;
            } else{
                mp[{std::min(u, v), std::max(u,v)}] &= w;
            }
        }

        vector<vector<pair<int,int>>> g(n);
        for(auto it : mp){
            int u = it.first.first;
            int v = it.first.second;
            int w = it.second;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<int> parent(n, -1);
        vector<int> val(n, INT_MAX);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                val[i] = dfs(g, i, i, parent, vis);
            }
        }

        int q = query.size();
        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++) {
            int u = query[i][0];
            int v = query[i][1];
            if (parent[u] == parent[v]) {
                ans[i] = val[parent[u]] & val[parent[v]];
            }
        }
        return ans;
    }

private:
    int dfs(vector<vector<pair<int,int>>>& g, int u, int &par, vector<int>& parent, vector<bool>& vis) {

        vis[u] = true;
        parent[u] = par;
        int x = INT_MAX;
        for (auto p : g[u]) {
            if (!vis[p.first]) {
                x &= dfs(g, p.first, par, parent, vis);
            }
            x &= p.second;
        }
        return x;
    }
};
