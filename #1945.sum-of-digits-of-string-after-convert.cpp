class Solution {
public:
    int getLucky(string s, int k) {

        int result = 0;
        for (auto a : s) {
            int val = a - 'a' + 1;
            result += val / 10 + val % 10;
        }
        
        k--;
        while (k--) {
            int tmp = 0;
            while (result) {
                tmp += result % 10;
                result /= 10;
            }
            result = tmp;
        }
        
        return result;
    }
};
