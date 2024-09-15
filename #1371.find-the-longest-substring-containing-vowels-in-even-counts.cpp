class Solution {
public:
    int findTheLongestSubstring(string s) {

        int mask_a = 1;
        int mask_e = 2;
        int mask_i = 4;
        int mask_o = 8;
        int mask_u = 16;
        int mask = 0;
        int result = 0;
        unordered_map<int,int> m = {{0, -1}};
        for (int i = 0; i != s.size(); i++) {
            switch (s[i]) {
                case 'a': mask ^= mask_a; break;
                case 'e': mask ^= mask_e; break;
                case 'i': mask ^= mask_i; break;
                case 'o': mask ^= mask_o; break;
                case 'u': mask ^= mask_u; break;
            }

            if (m.count(mask)) {
                result = std::max(result, i - m[mask]);
            } else {
                m[mask] = i;
            }
        }
    
        return result;
    }
};
