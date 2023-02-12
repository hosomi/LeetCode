class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int size = roads.size();
        vector <int> adj[size + 1];
        vector <int> indegree(size + 1);
        for (auto &i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]] += 1;
            indegree[i[1]] += 1;
        }

        queue <int> q;
        for(int i = 1; i <= size; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        vector <int> vis(size + 1);
        vector <int> cnt(size + 1, 1);
        long long result = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int node = q.front();
                int capa = cnt[node];
                q.pop();
                if (node == 0) {
                    continue;
                }

                vis[node] = 1; 
                result += (capa+seats-1)/seats;
                for (auto &i:adj[node]) {
                    if (vis[i]) {
                        continue;
                    }

                    indegree[i] -= 1;
                    cnt[i] += cnt[node];
                    if (indegree[i] == 1) {
                        q.push(i);
                    }
                }
            }
        }
        return result;
    }
};
