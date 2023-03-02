class Solution {
public:
    int compress(vector<char>& chars) {
        
        int size = chars.size();
        int anchor = 0;
        int result = 0;
        for (int read = 0; read < size; read++) {
            if (read == size - 1 
                || chars[read] != chars[read + 1]) {
                chars[result++] = chars[anchor];
                if (read > anchor) {
                    int count = read - anchor + 1;
                    for (char c : to_string(count)) {
                        chars[result++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        return result;
    }
};
