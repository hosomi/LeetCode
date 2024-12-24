class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        auto d1 = diameter(edges1);
        auto d2 = diameter(edges2);
        return std::max(std::max(d1, d2), (d1 + 1) / 2 +  (d2 + 1) / 2 + 1);
    }

private:
    int diameter(vector<vector<int>> const& edges) {

        int dia = 0;
        int n = edges.size() + 1;
        vector<unordered_set<int>> adj(n);
        for (auto const& e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }

        vector<bool> visited(n);
        function<int(int)> dfs;
        dfs = [&dfs, &dia, &adj, &visited] (int a) {
            visited[a] = true;
            int h1 = 0;
            int h2 = 0;  
            bool leaf = true;
            for (auto b : adj[a]) {
                if (!visited[b]) {
                    leaf = false;
                    int h = dfs(b);
                    if (h > h1) {
                        h2 = h1;
                        h1 = h;
                    } else if (h > h2) {
                        h2 = h;
                    }
                }
            }

            if (leaf) {
                return 1;
            }

            if (int curdia = (h2 == 0 ? h1 : h1 + h2); curdia > dia) {
                dia = curdia;
            }
            return h1 + 1;
        };
        
        dfs(0);
        return dia;
    }
};
