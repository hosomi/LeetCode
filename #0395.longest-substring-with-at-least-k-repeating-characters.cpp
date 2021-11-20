class Solution {
public:
    int longestSubstring(string s, int k) {

        int size = s.size();
        int i = 0;
        int result = 0;
        while (i + k <= size) {
            int mask[26] = {0};
            int least = 0;
            int index = i;
            for (int j = i; j < size; ++j) {
                int l = s[j] - 'a';
                ++mask[l];
                if (mask[l] < k) {
                    least |= (1 << l);
                } else {
                    least &= (~(1 << l));
                }
                if (least == 0) {
                    result = std::max(result, j - i + 1);
                    index = j;
                }
            }
            i = index + 1;
        }
        return result;
    }
};
