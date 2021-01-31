class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int result = 0;
        int index = -1;
        int size = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < size; ++i) {
            if (m.count(s[i]) && m[s[i]] > index) {
                index = m[s[i]];  
            }
            m[s[i]] = i;
            result = max(result, i - index);            
        }
        return result;
    }
};
