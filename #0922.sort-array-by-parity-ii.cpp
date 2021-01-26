class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& A) {

            int size = A.size();
            int i = 0;
            int j = 1;

            while (i < size && j < size) {
                if (A[i] % 2 == 0) {
                    i += 2;
                } else if (A[j] % 2 == 1) {
                    j += 2;
                } else {
                    swap(A[i], A[j]);
                }
            }
            return A;
        }
};
