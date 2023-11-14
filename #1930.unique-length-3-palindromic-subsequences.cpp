class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int size = s.size();
        vector<int> v1(26, INT_MAX);
        vector<int> v2(26);
        for (int i = 0; i < size; i++) {
            v1[s[i] - 'a'] = std::min(v1[s[i] - 'a'], i);
            v2[s[i] - 'a'] = i;
        }

        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (v1[i] < v2[i]) {
                set<char> st;
                for (int j = v1[i] + 1; j < v2[i]; j++) {
                    st.insert(s[j]);
                }
                result += st.size();
            }
        }
        return result;
    }
};
