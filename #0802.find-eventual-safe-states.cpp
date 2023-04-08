class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size = graph.size();
        vector<vector<int>> adj(size);
        vector<int> indegree(size, 0);
        for (int i = 0; i < size; i++) {
            for (int g : graph[i]) {
                adj[g].push_back(i);
                indegree[i] += 1;
            }
        }

        queue<int> q;
        for (int i = 0; i < size; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            result.push_back(front);

            for (auto x : adj[front]) {
                indegree[x] -= 1;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};
