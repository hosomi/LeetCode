class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int size = s.size();
        int count = 0;
        int prev = 0;
        int cur = 1;
        for (int i = 1; i < size; i++) {
            if (s[i]!=s[i-1]) {
                count += std::min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return count + std::min(prev, cur);
    }
};
