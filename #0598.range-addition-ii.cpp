class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int mmin = m;
        int nmin = n;
        for (vector<int>&o : ops) {
            mmin = std::min(mmin, o[0]);
            nmin = std::min(nmin, o[1]);
        }
        return mmin * nmin;
    }
};
