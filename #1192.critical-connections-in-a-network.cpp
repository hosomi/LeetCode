class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> v(n);
        for (vector<int>& connection : connections) {
            v[connection[0]].push_back(connection[1]);
            v[connection[1]].push_back(connection[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> node(n);
        vector<int> low(n);
        vector<int> parent(n, -1);
        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int time = 0;
                dfs(i, v, visited, node, low, parent, time, edges);
            }
        }
        return edges;
    }
    
private:
    void dfs(int i,
            vector<vector<int>>& v,
            vector<bool>& visited,
            vector<int>& node,
            vector<int>& low,
            vector<int>& parent,
            int& time,
            vector<vector<int>>& edges) {

        visited[i] = true;
        node[i] = low[i] = time++;
        for (int nei : v[i]) {
            if (!visited[nei]) {
                parent[nei] = i;
                dfs(nei, v, visited, node, low, parent, time, edges);
                low[i] = min(low[i], low[nei]);
                if (low[nei] > node[i]) {
                    edges.push_back({i, nei});
                }
            } else if(nei != parent[i]) {
                low[i] = std::min(low[i], node[nei]);
            }
        }
    };
};
