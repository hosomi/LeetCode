class Solution {
public:
    string sortVowels(string s) {

        vector<char> v;
        for (auto i : s) {
            char l = tolower(i);
            if (l == 'a' || l == 'e' 
                || l == 'u' || l == 'i'
                || l == 'o') {
                v.push_back(i);
            }
        }

        std::sort(v.begin(),v.end());

        int i = 0;
        for (auto &j : s) {
            char l = tolower(j);
            if (l == 'a' || l == 'e'
                || l == 'u' || l == 'i' || l == 'o') {
                j = v[i++];
            }
        }
        return s;
    }
};
