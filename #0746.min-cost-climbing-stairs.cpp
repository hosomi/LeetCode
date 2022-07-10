class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int size = cost.size();
        vector<int> v = vector<int>(size + 2, 0);
        for (int i = size - 1; i >= 0; i--) {
            v[i] = cost[i] + std::min(v[i + 1], v[i + 2]);
        }
        return std::min(v[0], v[1]);
    }
};
