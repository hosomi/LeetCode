class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n+1];
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans = 0;
        vector<int> visit(n, 0);
        for (int i = 0; i < n; ++i) {
            if (visit[i]) {
                continue;
            }
            
            int nodeCount = 0;
            int edgeCount = 0;
            dfs(i, adj, nodeCount, edgeCount, visit);
            if (nodeCount * (nodeCount-1) == edgeCount) {
                ans++;
            }
        }
        return ans;
    }

private:
    void dfs(int node, vector<int> adj[], int &nodeCount, int &edgeCount,vector<int> &visit) {

        visit[node] = 1;
        nodeCount++;
        edgeCount += adj[node].size();
        for (auto i : adj[node]) {
            if (!visit[i]) {
                dfs(i, adj, nodeCount, edgeCount, visit);
            }
        }
    }
};
