class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        int size = costs.size() / 2;
        std::nth_element(costs.begin(), costs.begin() + size, 
            costs.end(), [](vector<int>& v1, vector<int>& v2) {
                return v1[0] - v1[1] < v2[0] - v2[1];
            }
        );

        int result = 0;
        for (int i = 0; i < size; i++) {
            result += costs[i][0] + costs[i + size][1];
        }
        return result;
    }
};
