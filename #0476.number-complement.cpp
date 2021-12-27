class Solution {
public:
    int findComplement(int num) {

        if (num == 1) {
            return 0;
        }

        return (long)(1 << (int)(floor(log2(num)) + 1)) -1 - num;
    }
};
