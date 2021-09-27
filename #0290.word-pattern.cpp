class Solution {
public:
    bool wordPattern(string pattern, string s) {

        map<char, int> m1;
        map<string, int> m2;
        int i = 0;
        int size = pattern.size();
        istringstream is(s);
        for (string s; is >> s; i++){
            if(i == size || m1[pattern[i]] != m2[s]){
                return false;
            }

            m1[pattern[i]] = m2[s] = i + 1;
        }
        return i == size;
    }
};
