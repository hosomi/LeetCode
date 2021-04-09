class Solution {
public:
    string minWindow(string s, string t) {
        
        int counter = t.size();
        int start = 0;
        int end = 0;
        int top = 0;
        int index = INT_MAX;
        int size = s.size();
        vector<int> m(128,0);
        for(auto c: t) {
            m[c]++;
        }

        while (end < size) {
            if (m[s[end++]]-->0) {
                counter--;
            }

            while (counter == 0) {
                if (end - start < index) {
                    index = end - (top = start);
                }
                if (m[s[start++]] ++== 0) {
                    counter++;
                }
            }  
        }
        return index == INT_MAX? "" : s.substr(top, index);
    }
};
