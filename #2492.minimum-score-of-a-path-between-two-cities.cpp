class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int, int>>> m;
        for (auto &road: roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            
            m[u].push_back( { v, dist });
            m[v].push_back( { u, dist });
        }
        
        vector<bool> visited(n + 1, false);
        int minDist = INT_MAX;
        function<void(int)> dfs = [&](int node) {
            if (visited[node]) {
                return;
            }            
            visited[node] = true;
            
            for (auto [key, dist]: m[node]) {
                minDist = std::min(minDist, dist);
                dfs(key);
            }
        };
        dfs(1);
        return minDist;
    }
};
