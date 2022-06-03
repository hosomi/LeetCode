class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int size1 = str1.size();
        int size2 = str2.size();
        int div = greastestCommonDivisor(size1, size2);
        string divisor = str1.substr(0, div);
        std::regex pattern(("(" + divisor + ")+"));
        return std::regex_match(str1, pattern)
            && std::regex_match(str2, pattern) ? divisor: "";
    }

private:
    int greastestCommonDivisor(int x, int y) {

        return y == 0 ? x : greastestCommonDivisor(y, x % y);
    }
};
