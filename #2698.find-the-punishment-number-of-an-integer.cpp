class Solution {
public:
    int punishmentNumber(int n) {

        int c = 0;
        for (int i = 1; i <= n; i++) {
            string sq = to_string(i * i);
            if (dp(i, sq, 0)) {
                c += i * i;
            }
        }
        return c;
    }

private:
    bool dp(int val1, string &s, int in) {

        if (s.size() == in) {
            return val1 == 0;
        }

        int cur = 0;
        for (int i = in; i < s.size(); i++) {
            cur *= 10;
            cur += (s[i] - '0');
            if (val1 - cur < 0){
                return false;
            }

            if (dp(val1 - cur, s, i + 1)) {
                return 1;
            }
        }
        return 0;
    }
};
