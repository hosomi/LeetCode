class Solution {
public:
    string getHappyString(int n, int k) {

        k--;
        int pos = pow(2, n - 1);
        if (k >= pos * 3) {
            return "";
        }

        string s(n, ' ');
        s[0] = 'a' + (k / pos);
        k %= pos;
        pos /= 2;
        for (int i = 1; i < n; i++) {
            int ch = k / pos;
            k %= pos;
            pos /= 2;
            if (s[i - 1] == 'a') {
                ch++;
            }
            if (s[i - 1] == 'b' && ch == 1) {
                ch++;
            }
            s[i] = 'a' + ch;
        }
        return s;
    }
};
