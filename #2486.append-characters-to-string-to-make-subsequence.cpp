class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int j = 0;
        for (char c : s) {
            if (j == t.size()) {
                break;
            }

            if (t[j] == c) {
                j++;
            }
        }
        return t.size() - j; 
    }
};
