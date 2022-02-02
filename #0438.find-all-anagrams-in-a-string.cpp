class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if (s.empty()) {
            return {};
        }

        vector<int> result;
        vector<int> hs(26,0);
        vector<int> hp(26,0);
        int N = s.size();
        int L = p.size();
        for(char c:p) {
            ++hp[c-'a'];
        }

        for (int i=0; i<N; i++) {
            if (i >= L) {
                --hs[s[i-L] - 'a'];
            }
            ++hs[s[i]-'a'];
            if (hs == hp) { 
                result.push_back(i - L + 1);
            }
        }
        return result;
    }
};
