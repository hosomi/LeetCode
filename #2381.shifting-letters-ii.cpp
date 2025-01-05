class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        vector<int> line(s.size() + 1);
        for (const auto& shift : shifts) {
            line[shift[0]] += (shift[2] == 1 ? 1 : -1);
            line[shift[1] + 1] -= (shift[2] == 1 ? 1 : -1);
        }
        
        int shift = 0;
        for (int i = 0; i < s.size(); i++) {
            shift = (shift + line[i]) % 26;
            s[i] = ((s[i] - 'a') + shift + 26) % 26 + 'a';
        }
        return s;
    }
};
