class Solution {
public:
    int longestPalindrome(string s) {

        map<char, int> m;
        for (char c : s) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            } else {
                m[c]++;
            }
        }
        
        int result = 0;
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            result += it->second / 2 * 2;
            if (result % 2 == 0 && it->second % 2 == 1) {
                result++;
            }
        }
        return result;
    }
};
