class Solution {
public:
    string toHex(int num) {

        if (num == 0) {
            return "0";
        }
        
        unsigned int n = num < 0 ?
            UINT_MAX + 1 + (unsigned int)num : num;
        vector digits = {'0', '1', '2', '3',
                         '4', '5', '6', '7',
                         '8', '9', 'a', 'b',
                         'c', 'd', 'e', 'f'};
        string result;
        while (n > 0) {
            result = digits[n % 16] + result;
            n /= 16;
        }
        return result;
    }
};
