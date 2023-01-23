class Solution {
public:
    int balancedStringSplit(string s) {
        
        int size = s.size();
        int sum = 0;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == 'L') {
                sum++;
            }

            if (s[i] == 'R') {
                sum--;
            }

            if (sum == 0) {
                result++;
            }
        }
        return result;
    }
};
