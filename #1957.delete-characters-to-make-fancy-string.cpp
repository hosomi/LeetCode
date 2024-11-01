class Solution {
public:
    string makeFancyString(string s) {
        
        string str;
        for (int i = 0; i < s.size(); i++) {
            if (!(s[i] == s[i + 1] && s[i] == s[i + 2])) {
                str += s[i];
            }
        }
        return str;
    }
};
