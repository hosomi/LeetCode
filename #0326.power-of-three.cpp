class Solution {
public:
    bool isPowerOfThree(int n) {

        string s = "";
        while (n) {
            s.insert(0, std::to_string(n % 3));
            n /= 3;
        }
        std::regex pattern("^10*$");
        return std::regex_match(s, pattern);
    }
};
