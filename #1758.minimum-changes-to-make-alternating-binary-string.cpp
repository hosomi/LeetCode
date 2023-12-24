class Solution {
public:
    int minOperations(string s) {
        
        int size = s.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                if (s[i]=='1') {
                    left++;
                } else {
                    right++;
                }
            } else {
                if (s[i] == '0') {
                    left++;
                } else {
                    right++;
                }
            }
        }
        return std::min(left, right);
    }
};
