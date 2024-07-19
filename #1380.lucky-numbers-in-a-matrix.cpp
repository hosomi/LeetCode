class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> results;
        for (int i = 0; i < matrix.size(); i++) {
            int index = 0;
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] < matrix[i][index]) {
                    index = j;
                }
            }

            bool target = true;
            int val = matrix[i][index];
            for (int k = 0; k < matrix.size(); k++) {
                if (k == i) {
                    continue;
                }

                if (matrix[k][index] > val) {
                    target = false;
                    break;
                }
            }
            
            if (target) {
                results.push_back(val);
            }
        }
        return results;
    }
};
