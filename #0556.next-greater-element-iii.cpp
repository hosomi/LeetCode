class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);
        int size = s.size();
        char p = s[0];
        bool flg = 1;
        for (int i = 1; i < size; i++) {
            if (s[i] <= p) {
                p = s[i];
            } else {
                flg = 0;
            }
        }

        if (flg) {
            return -1;
        }

        std::next_permutation(s.begin(), s.end());
        
        if (std::stoll(s) > INT_MAX) {
            return -1;
        }

        return std::stoll(s);
    }
};
