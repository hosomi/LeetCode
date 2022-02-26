class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int size = graph.size();
        vector<vector<int>> v1(size, vector<int>(size, size * size));
        vector<vector<int>> v2(1 << size, vector<int>(size, size * size));

        for (int i = 0; i < size; i++) {
            for (auto j : graph[i]) {
                v1[i][j] = v1[j][i] = 1;
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    v1[j][k] = std::min(v1[j][k], v1[j][i] + v1[i][k]);
                }
            }
        }

        for (int i = 0; i < size; i++) {
            v2[1 << i][i] = 0;
        }

        for (int i = 0; i < (1 << size); i++) {
            for (int j = 0; j < size; j++) {
                if (i & 1 << j) {
                    for (int k = 0; k < size; k++) {
                        if (! (i & (1 << k))) {
                            v2[i | (1 << k)][k] = std::min(v2[i | (1 << k)][k], v2[i][j] + v1[j][k]);
                        }
                    }
                }
            }
        }

        int result = size * size;
        for (int i = 0; i < size; i++) {
            result = std::min(result, v2[(1 << size) - 1][i]);
        }
        return result;
    }
};
