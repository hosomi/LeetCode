class Solution {
public:
    long long minimumSteps(string s) {

        int64_t result = 0;
        for (int i = 0, c = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                result += i - c++;
            }
        }
        return result;
    }
};
