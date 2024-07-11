class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> st;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                reverse(s.begin() + st.top(), s.begin() + i);
                st.pop();
            }
        }

        for (auto c : s) {
            if (c != ')' && c != '(') {
                result += c;
            }
        }
        return result;
    }
};
