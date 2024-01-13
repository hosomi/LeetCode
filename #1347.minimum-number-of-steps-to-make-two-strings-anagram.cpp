class Solution {
public:
    int minSteps(string s, string t) {

        int size = s.size();
        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < size;i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }

        int result = 0;
        for (auto i : m1) {
            char c = i.first;
            if (m1[c] > m2[c]) {
                result += m1[c] - m2[c];
            }
        }
        return result;
    }
};
