class Solution {
public:
    int romanToInt(string s) {

        int length = s.length();
        int result = 0;
        for (int i = 0; i < length; i++) {
            result += mRomanNum[s[i]];
            if (i > 0 && mRomanNum[s[i]] > mRomanNum[s[i - 1]])
            result -= 2 * mRomanNum[s[i - 1]];
        }
        return result;
    }

private:
    map<char, int> mRomanNum {
        { 'I', 1 }, { 'V', 5 }, { 'X', 10 },
        { 'L', 50 }, { 'C', 100 }, { 'D', 500 },
        { 'M', 1000 }
    };
};
