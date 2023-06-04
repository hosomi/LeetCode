class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        vector<bool> visited(size, false);
        int count = 0;
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int i = 0; i < size; ++i) {
                if (isConnected[node][i] == 1 && !visited[i]) {
                    dfs(i);
                }
            }
        };
        
        for (int i = 0; i < size; ++i) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }
        return count;
    }
};
