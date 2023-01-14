class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int d[26]{};
        for (int i{}; i < 26; ++i) {
            d[i] = i;
        }
    
        for (int i{}; i < size(s1); ++i) {
            int x{s1[i] - 'a'};
            for( ; x != d[x]; x = d[x]);

            int y{s2[i] - 'a'};
            for( ; y != d[y]; y = d[y]);

            d[std::max(x, y)] = std::min(x, y);
        }

        for (auto &c : baseStr) {
            int x{c - 'a'};
            for ( ; x != d[x]; x=d[x]);
            c = 'a' + x;
        }           
        return baseStr;
    }
};
