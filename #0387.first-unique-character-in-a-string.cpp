class Solution {
public:
    int firstUniqChar(string s) {

        int length = s.length();
        unordered_map<char,int> m;
        for (int i = 0; i < length; i++) {
            m[s[i]]++;
        }

        for(int i = 0; i < length; i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
