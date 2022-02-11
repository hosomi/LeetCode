class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> v1(26, 0);
        for(char c : s1){
            v1[c-'a'] += 1;
        }

        int s1size = s1.size();
        int s2size = s2.size();
        vector<int> v2(26, 0);
        for (int i = 0; i < s2size; i++) {
            if (i < s1size) {
                v2[s2[i]-'a'] += 1;
            } else{
                v2[s2[i]-'a'] += 1;
                v2[s2[i - s1size]-'a'] -= 1;
            }

            if (v1 == v2) {
                return true;
            }
        }
        return false;
    }
};
