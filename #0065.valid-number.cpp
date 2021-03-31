class Solution {
public:
    bool isNumber(string s) {

        int left = 0;
        int right = s.size() - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisited = false;

        while (s[left] == ' ') {
            ++left;
        }

        while (s[right] == ' ') {
            --right;
        }

        if (left >= right && (s[left] < '0' || s[left] > '9')) {
            return false;
        }

        if (s[left] == '.') {
            dotExisted = true;
        } else if (s[left] >= '0' && s[left] <= '9') {
            digitExisited = true;
        } else if (s[left] != '+' && s[left] != '-') {
            return false;
        }

        for (int i = left + 1; i <= right - 1; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                digitExisited = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisited) {
                    eExisted = true;
                } else {
                    return false;
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (s[i] == '.') {
                if (!dotExisted && !eExisted) {
                    dotExisted = true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (s[right] >= '0' && s[right] <= '9') {
            return true;
        } else if (s[right] == '.' && !dotExisted && !eExisted && digitExisited) {
            return true;
        } else {
            return false;
        }
    }
};
