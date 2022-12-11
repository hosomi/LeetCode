class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {

        vector<int> result{1, 0};        
        for_each(begin(s), end(s), [&](auto c) {
            if ((result[1] += widths[c-'a']) > 100) {
                result[0]++;
                result[1] = widths[c-'a'];
            }
        });
        return result;
    }
};
