class Solution {
public:
    string fractionAddition(string expression) {
        
        int left_1 = 0;
        int right_1 = 1;
        int left_2;
        int right_2;
        char _;
        stringstream ss(expression);
        while(ss>>left_2>>_>>right_2) {
            left_1 = left_1 * right_2 + right_1 * left_2;
            right_1 *= right_2;
            int gcd = std::gcd(left_1, right_1);
            left_1 /= gcd;
            right_1 /= gcd;
        }
        return to_string(left_1) + "/" + to_string(right_1);
    }
};
