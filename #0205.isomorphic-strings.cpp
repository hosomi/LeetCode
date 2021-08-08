class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int size = s.size();
        vector<int> vs(128, 0);
        vector<int> vt(128, 0);
        for (int i = 0; i < size; i++) {
            if (vs[s[i]] != vt[t[i]]){
                return false;
            }
            vs[s[i]] = i + 1;
            vt[t[i]] = i + 1;
        }
        return true;
    }
};
