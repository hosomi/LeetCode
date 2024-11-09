class Solution {
public:
    long long minEnd(int n, int x) {

        int idx = 0;
        bitset<64> n_bin(n - 1);
        bitset<64> result(x);
        for (int i = 0; i < 64; i++) {
            if (!result[i]) {
                result[i] = n_bin[idx];
                idx++;
            }
        }
        return result.to_ullong();   
    }
};
