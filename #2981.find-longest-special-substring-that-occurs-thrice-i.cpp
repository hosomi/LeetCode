class Solution {
public:
    int maximumLength(string s) {

        int n = s.size();
        int max = -1;
        map<pair<char, int>, int> m;
        for (int i = 0, j = 0; i < n; i = j) {
            int len = 0 ;
            while (j < n && s[i] == s[j]) {
                j++;
                len++;
            }
            if (len > 0 && (m[{s[i], len - 0}] += 1) >= 3) {
                max = std::max(max, len - 0);
            }
            if (len - 1 > 0 && (m[{s[i], len - 1}] += 2) >= 3) {
                max = std::max(max, len - 1);
            }
            if (len - 2 > 0 && (m[{s[i], len - 2}] += 3) >= 3) {
                max = std::max(max, len - 2);
            }
        }
        return max;
    }
};
