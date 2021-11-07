class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        dfs(s, 0, 0, '(', ')');
        return result;
    }

private:
    vector<string> result;

    void dfs(string s, int start, int end, char open, char close) {

        int index = 0;
        for (int i = start; i < s.length(); i++) {
            index += s[i] == open ? 1 : s[i] == close ? -1 : 0;
            if (index == -1) {
                int j = i;
                while (end <= j) {
                    if ((j == end || s[j - 1] != s[j]) && s[j] == close) {
                        dfs(s.substr(0, j) + s.substr(j + 1), i, j, open, close);
                    }
                    j--;
                }
                return;
            }
        }

        std::reverse(s.begin(), s.end());
        if (open == '(') {
            dfs(s, 0, 0, close, open);
        } else {
            result.push_back(s);
        }
    }
};
