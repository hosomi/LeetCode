class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        
        int size = A.size();
        int arraySize = A[0].size();
        int result = 0;

        for (int i = 0; i < arraySize; ++ i) {
            for (int j = 1; j < size; ++ j) {
                if (A[j - 1][i] > A[j][i]) {
                    ++ result;
                    break;
                }
            }
        }
        return result;
    }
};
