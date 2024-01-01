class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int sindex = s.size() - 1;
        int gindex = g.size() - 1;
        int result = 0;
        for(int i = gindex; i >= 0;i--) {
            if (sindex >= 0 && s[sindex] >= g[i]) {
                result++;
                sindex--;
            }
        }
        return result;
    }
};
