class Solution {
public:
    string reverseOnlyLetters(string s) {

        int size = s.size();
        string result(size,  'a');
        for (int i = 0; i < size; i++) {
            if (!std::isalpha(s[i])) {
                result[i] = s[i];
            }
        }
        
        int j = size - 1;
        for (int i = 0; i < size; i++) {
            if (!std::isalpha(s[i])) {
                continue;
            }

            while (!std::isalpha(result[j])) {
                j--;
            }
            result[j--] = s[i];
        }
        return result;
    }
};
