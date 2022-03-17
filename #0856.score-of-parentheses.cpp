class Solution {
public:
    int scoreOfParentheses(string s) {

        int size = s.size();
        int result = 0;
        int parentheses = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                parentheses++;
                continue;
            }

            parentheses--;
            if (s[i - 1] == '(') {
                result += (1 << parentheses);
            }
        }
        return result;
    }
};
