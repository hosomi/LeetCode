class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;  
        } 

        int flag[26] = {0};
        for (char c : s) {
            flag[c - 'a'] ++;
        }

        for (char c : t) {
            if (-- flag[c - 'a'] == -1) {
                return false;
            }
        }
        return true;
    }
};
