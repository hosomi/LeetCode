class Solution {
public:
    int reverse(int x) {

        int result = 0;
        int remainder;
        while (x) {
            remainder = x % 10;
            x /= 10;
            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && remainder > 7)) {
                return 0;
            }
                
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && remainder < -8)) {
                return 0;
            }
            
            result = result * 10 + remainder;
        }
        
        return result;
    }
};
