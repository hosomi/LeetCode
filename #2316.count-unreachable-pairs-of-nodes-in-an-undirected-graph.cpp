class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        int size = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < size; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
		
        vector<bool> vis(n);
        vector<int> v;
        int count=0;
        for (int i=0; i < n; i++) {
            if (!vis[i]) {
                count = 0;
                dfs(i, vis, adj, count);
                v.push_back(count);
            }
        }

        size = v.size();
        long long int rem = n;
        long long int result = 0;
        for (int i = 0; i < size; i++){
            result += ((long long)v[i] * (rem - v[i]));
            rem = rem - v[i];
        }
        return result;
    }

private:
    int sum;
    void dfs(int node, vector<bool>& vis,
        vector<vector<int>>& adj, int& count){
        
        count++;
        vis[node] = true;
        for (int x: adj[node]) {
            if (!vis[x]) {
                dfs(x, vis, adj, count);
            }
        }
    }
};
