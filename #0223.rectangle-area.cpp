class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int rectilinear = 0;
        if (ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2) {
            rectilinear = 0;
        } else {  
            rectilinear = (std::min(ax2, bx2) - std::max(ax1, bx1))
                * (std::min(ay2, by2) - std::max(ay1, by1));
        }
        return (bx2 - bx1) * (by2 - by1) + (ax2 - ax1) * (ay2 - ay1) - rectilinear;
    }
};
