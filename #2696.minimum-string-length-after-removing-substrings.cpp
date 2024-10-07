class Solution {
public:
    int minLength(string s) {

        string result;
        for (char c : s) {
            if (!result.size()) {
                result += c;
            } else if (c == 'B' && result.back() == 'A') {
                result.pop_back();
            } else if (c == 'D' && result.back() == 'C') {
                result.pop_back();
            } else {
                result += c;
            }
        }
        return result.size();
    }
};
