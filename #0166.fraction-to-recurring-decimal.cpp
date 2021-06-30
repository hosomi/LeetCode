class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        map<long long int, long long int> m;
        long long int numll = std::llabs(numerator);
        long long int denll = std::llabs(denominator);
        string result;

        result += std::to_string(numll / denll);
        if (numll % denll != 0) {
            result += ".";
        }

        while (numll % denll != 0) {
            numll %= denll;
            numll *= 10;

            if (m.find(numll) == m.end()) {
                m[numll] = result.size();
                result += std::to_string(abs(numll / denll));
            } else {
                result = result.substr(0, m[numll])
                    + "(" + result.substr(m[numll], result.size() - m[numll]) + ")";
                break;
            }
        }

        if ((numerator > 0 && denominator < 0)
            || (numerator < 0 && denominator > 0)) {

            result = "-" + result;
        }
        return result;
    }
};
