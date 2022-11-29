class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        std::sort(dictionary.begin(), dictionary.end(),
            [](const string& l, const string& r) {
                return (l.size() == r.size()) ? l < r : l.size() > r.size();
        });
        
        int size = s.size();
        int dsize;
        for (string& d : dictionary) {
            dsize = d.size();
            int l = 0;
            int r = 0;
            while (l < dsize && r < size) {
                if (d[l] == s[r]) {
                    l++;
                    r++;
                } else {
                    r++;
                }
            }

            if (l == dsize) {
                return d;
            }
        }
        return "";
    }
};
