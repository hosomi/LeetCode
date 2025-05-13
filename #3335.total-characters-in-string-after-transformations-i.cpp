class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

        int M = 1e9 + 7;
        vector<int> hm(26);
        for(auto c:s) hm[c-'a']++;
        while (t--) {
            int z  =hm[25];
            for (int i=24; i >= 0; i--) {
                hm[i + 1] = hm[i];
                hm[i] = 0;
            }

            hm[0] = ((hm[0]) % M + z % M) % M;
            hm[1] = ((hm[1]) % M + z % M) % M;
        }

        int ans = 0;
        for (auto x : hm) {
            ans= (ans % M + x % M) % M;
        }
        return ans;
    }
};
