class Solution {
public:
    int minimumLength(string s) {

        int n = s.size();
        vector<int> v(26, 0);
        for (int i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i] == 0) {
                continue;
            }

            ans += v[i] % 2 ? 1 : 2;
        }  
        return ans;
    }
};
