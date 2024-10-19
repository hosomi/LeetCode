class Solution {
public:
    char findKthBit(int n, int k) {
        
        if (n == 1 && k == 1) {
            return '0';
        }

        if (k == 2) {
            return '1';
        }

        int mid = pow(2, n - 1);
        if (k < mid) {
            return findKthBit(n - 1, k);
        }
        
        if (k == mid) {
            return '1';
        }

        if (findKthBit(n - 1, (2 * mid -k)) =='1') {
            return '0';
        }

        return '1';
    }
};
