class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int size = colors.size();
        vector<vector<int>> adj(size);
        vector<int> indegree(size);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> count(size, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < size; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int result = 0;
        int seen = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result = std::max(result,
                ++count[node][colors[node] - 'a']);
            seen++;
            for (auto& neighbor : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    count[neighbor][i] =
                        std::max(count[neighbor][i], count[node][i]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return seen == size ? result : -1;
    }
};
