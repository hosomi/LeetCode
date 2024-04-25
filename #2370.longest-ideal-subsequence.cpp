class Solution {
public:
    int longestIdealString(string s, int k) {

        map<char, int> p;
        int result = 0;
        for (char c : s) {
            int max = 0;
            for (int i = 0; i <= k; i++) {
                max = std::max(max, p[int(c) - i]);
                max = std::max(max, p[i + int(c)]);
            }
            p[int(c)] = 1 + max;
            result = std::max(result, p[c]);
        }
        return result;
    }
};
