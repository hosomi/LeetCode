class Solution {
public:
    int minimumOneBitOperations(int n) {
        
	    int left = 0;
        int right = 0;
        for (int i = 1; n; n >>= 1, i <<= 1) {
            right += i;
            if (n % 2) {
                swap(right, left);
            }
        }
        return left;
    }
};
