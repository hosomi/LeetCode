class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int, int> m;
        std::sort(edges.begin(), edges.end());
        for (auto const& edge : edges)  {
            if (m.count(edge[1]) > 0) {
                m[edge[0]] = edge[1];
            } else {
                m[edge[1]] = edge[0];
            }
        }
    
        int size = hasApple.size();
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (!hasApple[i]) {
                continue;
            }

            int parent = i;
            while (parent != 0 && m[parent] >= 0) {
                auto temp = m[parent];
                m[parent] = -1;
                parent = temp;
                result += 2;
            }
        }
        return result;
    }
};
