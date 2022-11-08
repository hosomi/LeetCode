class Solution {
public:
    string makeGood(string s) {

        int i = 0;
        while (i + 1 < s.size()) {
            if (abs(s[i] - s[i+1]) == 32) {
                s.erase(i, 2);
                if (i > 0) {
                    --i;
                }
            } else {
                ++i;
            }
        }
        return s;
    }
};
