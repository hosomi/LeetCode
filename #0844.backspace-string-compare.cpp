class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int length = s.length();
        stack<char> st1;
        stack<char> st2;
        for (int i = 0; i < length; i++) {
            if (s[i]=='#') {
                if (!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(s[i]);
            }
        }

        length = t.length();
        for (int i = 0; i < length; i++) {
            if (t[i] == '#') {
                if (!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(t[i]);
            }
        }
        return st1 == st2;
    }
};
