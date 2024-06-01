class Solution {
public:
    int scoreOfString(string s) {
        
        int result = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            result += std::abs((s[i] - 'a') - (s[i + 1] - 'a'));
        }    
        return result;
    }
};
