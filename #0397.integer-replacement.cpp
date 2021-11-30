class Solution {
public:
    int integerReplacement(int n) {

        if (n == 1) {
            return 0;
        }

        if (n % 2 == 0) {
            return integerReplacement(n/2)+1;  
        }
        
        return std::min(integerReplacement(((long)n + 1) / 2),
                        integerReplacement((n - 1) / 2)) + 2;
    }
};
