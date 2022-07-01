class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        std::sort(begin(boxTypes), end(boxTypes),
            [](auto& left, auto& right) {
                return left[1] > right[1];
            }
         );

        int unit = 0;
        for(auto& box : boxTypes) {
            if (truckSize <= 0) {
                break;
            }
            unit += std::min(truckSize, box[0]) * box[1];
            truckSize -= box[0];
        }
        return unit;
    }
};
