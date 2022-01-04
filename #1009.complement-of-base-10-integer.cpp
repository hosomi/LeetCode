class Solution {
public:
    int bitwiseComplement(int n) {

        if (n == 0) {
            return 1;
        }

        for (int i = 0; i < 32; ++i) {
            unsigned int j = (1 << i);
            if (j > n) {
                return (j - 1 - n);
            }
        }
        return 0;
    }
};
