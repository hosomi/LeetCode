class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        return std::min(rec2[2]-rec1[0], rec1[2]-rec2[0]) > 0
            && std::min(rec2[3]-rec1[1], rec1[3]-rec2[1]) > 0;
    }
};
