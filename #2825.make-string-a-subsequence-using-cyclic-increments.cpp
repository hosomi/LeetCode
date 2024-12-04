class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        for (auto i = begin(str1), j = begin(str2); i != end(str1); ++i) {
            if ((*i == *j || *i + 1 == *j || *i - 25 == *j)
                && ++j == end(str2)) {
                return true;
            }
        }
        return false;
    }
};
