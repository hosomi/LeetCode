class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto node : redEdges) {
            graph[node[0]].push_back(make_pair(node[1], 0));
        }

        for (auto node : blueEdges) {
            graph[node[0]].push_back(make_pair(node[1], 1));
        }
        
        int visited[n][2];
        memset(visited, -1, sizeof visited);
        visited[0][0] = 0;
        visited[0][1] = 0;

        queue <pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                for (auto child : graph[curr.first]) {
                    if (visited[child.first][child.second] == -1 && child.second != curr.second) {
                        q.push(child);
                        visited[child.first][child.second] = visited[curr.first][curr.second] + 1;
                    }
                }
            }
        }
        
        vector<int> result;
        for (auto i : visited) {
            std::min(i[0], i[1]) == -1 ? result.push_back(std::max(i[0], i[1]))
                : result.push_back(std::min(i[0], i[1]));
        }
        return result;
    }
};
