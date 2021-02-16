class Solution {
public:
    bool isValid(string s) {

        map<char, char> determine{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> sc;
        for (char c : s) {
            if (!determine.count(c)) {
                sc.push(c);
            } else {
                if (sc.empty() || determine[c] != sc.top()) {
                    return false;
                }
                sc.pop();
            }
        }
        return sc.empty();
    }
};
