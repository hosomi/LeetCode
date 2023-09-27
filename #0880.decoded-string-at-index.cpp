class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int length = s.length();
        long size = 0;
        for (int i = 0; i < length; i++) {
            if (isdigit(s[i])) {
                size = size * (s[i] - '0');
            } else { 
                size++;
            }
        }

        for (int i = length - 1; i >= 0; i--) {
            k = k % size;
            if (k == 0 && isalpha(s[i])) {
                return (string) "" + s[i];
            }

            if (isdigit(s[i])) { 
                size = size / (s[i]-'0');
            }
            else { 
                size--;
            }
        }
        return "";
    }
};
