class Solution {
public:
    string removeStars(string s) {
        
        string result;
        for (char c : s) {
            if (c == '*' && !result.empty()) {
                result.pop_back();
            } else if (c != '*') {
                result.push_back(c);
            }
        }
        return result;
    }
};
