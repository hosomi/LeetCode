class Solution {
public:
    int maxPower(string s) {

        int size = s.size();
        if (size == 0) {
            return size;
        }

        int result = 1;
        int j = 1;
        char c = s[0];
        for (int i = 1; i < size; i++) {
            if (s[i] == c) {
                j++;
            }
            
            if (s[i] != c || i == s.size()-1) {
                result = std::max(result, j);
                j = 1;
            }
            c = s[i];
        }
        return result;
    }
};
