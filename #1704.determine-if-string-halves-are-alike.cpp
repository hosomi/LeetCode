class Solution {
public:
    bool halvesAreAlike(string s) {

        int size = s.size();
        unordered_set<char> uset {'a', 'e', 'i',
            'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = 0;
        for (int i = 0; i < size; i++) {
            if (uset.find(s[i]) != uset.end()) {
                if (i < size / 2) {
                    left++;
                } else {
                    right++;
                }
            }
        }
        return left == right;
    }
};
