class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                if (t == "+") {
                    st.push(first + second);
                } else if (t == "-") {
                    st.push(second - first);
                } else if (t == "*") {
                    st.push(first * second);
                } else {
                    st.push(second / first);
                }
            } else {
                st.push(atoi(t.c_str()));
            }
        }
        return st.top();
    }
};
