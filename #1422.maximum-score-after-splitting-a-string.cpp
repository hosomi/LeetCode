class Solution {
public:
    int maxScore(string s) {
        
        int size = s.size();
        map<char, int>m1;
        for (int i = 0; i < size; i++) {
            m1[s[i]]++;
        }
        
        map<char, int>m2;
        int result = 0;
        for (int i = 0; i < size - 1; i++) {
            m1[s[i]]--;
            m2[s[i]]++;
            result = std::max(result, m1['1'] + m2['0']);
        }
        return result;
    }
};
