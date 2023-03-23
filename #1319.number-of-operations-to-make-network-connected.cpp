class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> v[n];
        for (auto c : connections) {
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }
    
        vector<int> visited(n,0);
        int resCount = 0;
        int edgeCount = 0;
        int compCount=0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nEdges = 0;
                int nVertices = 0;
                dfs(i, v, visited, nEdges, nVertices);
                compCount++;
                nEdges /= 2;
                edgeCount += nEdges;
                resCount += (nEdges - (nVertices-1));
            }
        }

        if (edgeCount < n - 1 || resCount < compCount - 1) {
            return -1;
        }

        return compCount - 1;
    }

private:
    void dfs(int u, vector<int> v[], vector<int> &visited,
        int &nEdges, int &nVertices) {

        visited[u] = 1;
        nVertices++;
        for (auto a : v[u]) {
            nEdges++;
            if (a != u && !visited[a]) {
                dfs(a, v, visited, nEdges, nVertices);
            }
        }
    }
};
