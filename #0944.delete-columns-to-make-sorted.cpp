class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int size = strs.size();
        int arraySize = strs[0].size();
        int result = 0;

        for (int i = 0; i < arraySize; ++ i) {
            for (int j = 1; j < size; ++ j) {
                if (strs[j - 1][i] > strs[j][i]) {
                    ++ result;
                    break;
                }
            }
        }
        return result;
    }
};
