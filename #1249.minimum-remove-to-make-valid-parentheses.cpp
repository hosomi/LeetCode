class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i+1);
            } else if(s[i] == ')') {
                if (stk.size() > 0 && stk.top() > 0) {
                    stk.pop();
                } else {
                    stk.push(-(i + 1));
                }
            }
        }

        while (!stk.empty()) {
            int i = stk.top(); stk.pop();
            s.erase(abs(i)-1, 1);
        }
        return s;
    }
};
