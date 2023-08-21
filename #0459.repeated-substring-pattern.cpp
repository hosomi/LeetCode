class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string s2 = s + s;
        return s2.substr(1, s2.size() - 2).find(s) != -1 ? 1 : 0;
    }
};
