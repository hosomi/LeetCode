class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        string str = to_string(n);
        int size = digits.size();
        int len = str.size();
        int result = 0;
        for (int i = 1; i < len; ++i) {
            result += pow(size, i);
        }

        for (int i = 0; i < len; ++i) {
            bool flag = false;
            for (string &d : digits) {
                if (d[0] < str[i]) {
                    result += pow(size, len - 1 - i);
                } else if (d[0] == str[i]) {
                    flag = true;
                }
            }
            if (!flag) {
                return result;
            }
        }
        return result + 1;
    }
};
