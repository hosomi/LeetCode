class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        int n1 = s.size();
        int n2 = spaces.size();
        string s2(n1 + n2, ' ');
        for (int i = 0, j = 0, k = 0; i < s2.size(); i++) {
            if (j < n2 && spaces[j] == k) {
                j++;
            } else {
                s2[i] = s[k++];
            }
        }
        return s2;
    }
};
