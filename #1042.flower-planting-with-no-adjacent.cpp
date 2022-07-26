class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<int> result(n);
        vector<vector<int>> graph(n);
        for (vector<int>& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        
        for (int i = 0; i < n; i++) {
            vector<int> colors(5);
            for (int j : graph[i]) {
                colors[result[j]] = 1;
            }
            
            for (int k = 1; k <= k; k++) {
                if (!colors[k]) {
                    result[i] = k;
                    break;
                }
            }
        }

        return result;
    }
};
