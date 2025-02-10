class Solution {
public:
    string clearDigits(string s) {

        string ans;
        for (char c : s) {
            if (isalpha(c)) {
                ans += c;
            } else if (ans.size()) {
                ans.pop_back();
            }
        }
        return ans;
    }
};
