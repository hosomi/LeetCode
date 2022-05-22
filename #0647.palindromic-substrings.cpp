class Solution {
public:
    int countSubstrings(string s) {

        int size = s.size();
        int result = 0;
        for (int i = 0; i < 2 * size -1; i++) {
            int left = i / 2;
            int right = i / 2 + i % 2;
            while (left >= 0 && right < size && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};
