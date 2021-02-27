class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        int index = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    index = i + 1;
                } else {
                    st.pop();
                    result = max(result, st.empty() ? i - index + 1 : i - st.top());          
                }
          }
        }
        return result;
    }
};
