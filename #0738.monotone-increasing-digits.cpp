class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string s = to_string(n);
        int size = s.size();
        int i = 1;
        while (i < size and s[i-1] <= s[i]) {
            i++;
        }

        if (i < size) {
            while (i > 0 and s[i] < s[i-1]) {
                i--;
                s[i]--;
            }
        }

        for (int j = i + 1; j < size; j++) {
            s[j] = '9';
        }
        return std::stoi(s);
    }
};
