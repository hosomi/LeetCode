class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        map<int,priority_queue<int>> adj;
        map<int, int> outdegree;
        int start = -1;
        for (auto i: pairs) {
            adj[i[0]].push(i[1]);
            outdegree[i[0]]++;
            outdegree[i[1]]--;
        }

        for (auto i: outdegree) {
            if (i.second > 0) {
                start = i.first;
            }
        }
        
        if (start == -1) {
            start = pairs[0][0];
        }
        cout<<start<<" ";
        vector<vector<int>> ans;
        dfs(start, -1, adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(int node, int parent, map<int, priority_queue<int>> &adj, vector<vector<int>> &ans) {

        while (!adj[node].empty()) {
            auto temp = adj[node].top();
            adj[node].pop();
            dfs(temp,node,adj,ans);
        }

        if (parent != -1) {
            ans.push_back({parent, node});
        }
    }
};
