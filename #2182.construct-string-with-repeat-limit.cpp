class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string s2;
        for (int i = 25; i >= 0; i--) {
            while (count[i] > repeatLimit) {
                for (int j = 0; j < repeatLimit; j++) {
                    s2.push_back('a' + i);
                }

                count[i] -= repeatLimit;
                int j = i - 1;
                while (j >= 0 && count[j] == 0) {
                    j--;
                }

                if (j == -1) {
                    return s2;
                }

                count[j]--;
                s2.push_back('a' + j);
            }

            for (int j = 0; j < count[i]; j++) {
                s2.push_back('a' + i);
            }
        }
        return s2;
    }
};
