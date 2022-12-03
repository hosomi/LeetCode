class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        std::sort(s.begin(), s.end(),
            [&m](const char l, const char r) {
                return (m[l] == m[r]) ? l < r : m[l] > m[r];
        });
        return s;
    }
};
