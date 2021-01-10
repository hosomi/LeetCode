class Solution {
public:
    int numDecodings(string s) {

        if (s.empty()) {
            return 0;
        }

        int size = s.size();
        vector<int> vs(size + 1);
        vs[0] = 1;
        for (int i = 1; i <= size; i ++ ) {
            if (s[i - 1] < '0' || s[i - 1] > '9') {
                return 0;
            }

            vs[i] = 0;
            if (s[i - 1] != '0') {
                vs[i] = vs[i - 1];
            }

            if (i > 1) {
                int z = (s[i-2]-'0') * 10 + s[i-1] - '0';
                if (z >= 10 && z <= 26) {
                    vs[i] += vs[i - 2];
                }
            }
        }
        return vs[size];
    }
};
