class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        int size = edges.size();
        vector<int> distnodes(size, 0);
        vector<bool> visited(size, false);
        vector<bool> extra(size,false);
        int result = -1;
        for(int i = 0; i < size; i++) {
            if (visited[i]==false) {
                dfs(i, distnodes, visited, extra, 0, result, edges);
            }
        }

        return result;
    }

private:
    void dfs(int node, vector<int>& distnode,
        vector<bool>& visited, vector<bool>& extra,
        int distance, int& result, vector<int>& edges) {

        if (node == -1) {
            return;
        }

        if (!visited[node]) {
            visited[node] = true;
            extra[node] = true;
            distnode[node] = distance;
            dfs(edges[node], distnode, visited, extra,
                distance + 1, result, edges);
        } else if(extra[node]) {
            result = std::max(result, distance - distnode[node]);
        }

        extra[node] = false;
    }
};
