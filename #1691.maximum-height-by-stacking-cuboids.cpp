class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for (auto& c : cuboids) {
            std::sort(begin(c), end(c));
        }

        cuboids.push_back({0, 0, 0});
        sort(begin(cuboids), end(cuboids));
        int size = cuboids.size();
        vector<int> max(size);
        int result = 0;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0]
                    && cuboids[j][1] <= cuboids[i][1]
                    && cuboids[j][2] <= cuboids[i][2]) {
                    max[i] = std::max(max[i], max[j] + cuboids[i][2]);
                    result = std::max(result, max[i]);
                }
            }
        }
        return result;
    }
};
