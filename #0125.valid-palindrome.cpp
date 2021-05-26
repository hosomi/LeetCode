class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty()) {
            return true;
        }

        const char* c1 = s.c_str();
        const char* c2 = c1 + s.length() - 1;
        while (c2 > c1) {
            if (!std::isalnum(*c1)) {
                ++c1; continue;
            }

            if (!std::isalnum(*c2)) {
                --c2; continue;
            }

            if (std::tolower(*c1) != std::tolower(*c2)) {
                return false;
            } else {
                --c2;
                ++c1;
            }
        }
        return true;
    }
};
