class Solution {
public:
    bool sumGame(string num) {

        int size = num.size();
        int right = 0;
        int sum = 0;
        for (int i = 0; i < size / 2; i++) {
            if (num[i] == '?') {
                sum++;
            } else {
                right += num[i] - '0';
            }   
        }

        for (int i = size / 2; i < size; i++) {
            if (num[i] == '?') {
                sum--;
            } else {
                right -= num[i] - '0';
            }
        }

        if (right == 0) {
            return !(sum == 0);
        }

        if (right < 0) {
            if (sum <= 0) {
                return true;
            }
            return !((right + sum / 2 * 9) >= 0 && (right + (sum + 1) / 2 * 9) <= 0);
        }

        if (sum >= 0) {
            return true;
        }

        int last = -sum;
        return !((right - last / 2 * 9) <= 0 && (right - (last + 1) / 2 * 9) >= 0);
    }
};
