class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int maxDistance = 0;
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            maxDistance = std::max(maxDistance,
                std::abs(arrays[i].back() - minVal));
            maxDistance = std::max(maxDistance,
                std::abs(maxVal - arrays[i].front()));
            minVal = std::min(minVal, arrays[i].front());
            maxVal = std::max(maxVal, arrays[i].back());
        }
        return maxDistance;
    }
};
