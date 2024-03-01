class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        std::sort(s.begin(), s.end());
        string s2 = s;
        s2.pop_back();
        sort(s2.rbegin(), s2.rend());
        return s2 + '1';
    }
};
