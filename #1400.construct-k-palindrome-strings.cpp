class Solution {
public:
    bool canConstruct(string s, int k) {

        int cnt = 0;
        int freq[26] = {};
        for (char c : s) {
            ++freq[c - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            cnt += (freq[i] % 2);
        }
        return cnt <= k && s.size() >= k;
    }
};
