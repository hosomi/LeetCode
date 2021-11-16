class Solution {
public:
    bool isSubsequence(string s, string t) {

        string::iterator it = s.begin();
        for (char c : t) {
            it += (c == *it);
        }
        return it == s.end();
    }
};
