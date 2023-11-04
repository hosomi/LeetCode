class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        int l = right.empty() ? 0 : n -
            *std::min_element(right.begin(), right.end());
        int r = left.empty() ? 0 : 
            *std::max_element(left.begin(), left.end());
        return std::max(l, r);
    }
};
