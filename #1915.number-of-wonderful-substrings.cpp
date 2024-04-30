class Solution {
public:
    long long wonderfulSubstrings(string word) {

        unordered_map<int,int> m = {{0, 1}};
        int mask = 0;
        long long result = 0;
        for (char w : word) {
            mask ^= 1 << (w - 'a');
            result += m[mask];
            for (char i = 'a'; i <= 'j'; i++) {
                result += m[mask ^(1 << (i - 'a'))];
            }
            m[mask]++;
        }
        return result;
    }
};
