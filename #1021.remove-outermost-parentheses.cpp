class Solution {
public:
    string removeOuterParentheses(string s) {

        int left = -1;
        int right = -1;
        int balance = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '('){
                if (left == -1) {
                    left = i;
                }
                balance++;
            } else if(s[i] == ')'){
                balance--;
            }
    
            if (balance == 0) {
                right = i;
                s.erase(s.begin() + right);
                s.erase(s.begin() + left);
                left = -1;
                right = -1;
                i = i - 2 + 1;
            } else {
                i++;
            }
        }
        return s;
    }
};
