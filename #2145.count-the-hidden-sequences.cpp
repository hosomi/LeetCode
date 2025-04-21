class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        int l = 0;
        int r = 0;
        int cur = 0;
        for (int difference : differences) {
            cur += difference;
            l = std::min(l, cur);
            r = std::max(r, cur);
            if (r - l > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (r - l) + 1;
    }
};
