class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();
        if (n % 2) {
            return false;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (s[i] == '(' || locked[i] == '0') ? 1 : -1;
            if (cnt < 0) {
                return false;
            }
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt += (s[i] == ')' || locked[i] == '0') ? 1 : -1;
            if (cnt < 0) {
                return false;
            }
        }
        return true;
    }
};
