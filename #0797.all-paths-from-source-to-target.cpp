class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path = {0};
        vector<vector<int>> paths;
        
        dfs(graph, 0, path, paths);
        
        return paths;
    }

private:
    void dfs(vector<vector<int>>& graph,
             int index,
             vector<int>& path,
             vector<vector<int>>& paths) {

        int size = graph.size();
        if (index == size - 1) {
            paths.push_back(path);
        } else {
            for (int nei : graph[index]) {
                path.push_back(nei);
                dfs(graph, nei, path, paths);
                path.pop_back();
            }
        }
    };
};
