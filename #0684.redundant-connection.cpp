class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int, int> graph;
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            while (graph[a] != 0) {
                a = graph[a];
            }

            while (graph[b] != 0) {
                b = graph[b];
            }

            if (a == b) {
                return edge;
            }

            graph[b] = a;
        }
        return {-1, -1};
    }
};

//
// Wrong Answer
//
// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//        
//         int size = edges.size();
//         for (int i = size - 1; i >= 0; i--) {
//             int x = edges[i][0];
//             int y = edges[i][1];
//             bool first = false;
//             bool second = false;
//             for (int j = 0; j < i; j++) {
//                 if (find(edges[j].begin(), edges[j].end(), x) != edges[j].end()) {
//                     first = true;
//                 } else if (find(edges[j].begin(), edges[j].end(), y) != edges[j].end()) {
//                     second = true;
//                 }

//                 if (first && second) {
//                     return edges[i];
//                 }
//             }
//         }
//         return vector<int>();
//     }
// };
