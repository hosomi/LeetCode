class Solution {
public:
    int countSegments(string s) {

        if (s.empty()) {
            return 0;
        }
        
        int size = s.size();
        bool lastIsSpace = true;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == ' ') {
                lastIsSpace = true;
            } else if (lastIsSpace) {
                lastIsSpace = false;
                result++;
            }
        }
        return result;
    }
};
