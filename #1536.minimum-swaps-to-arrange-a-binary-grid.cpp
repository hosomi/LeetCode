class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int size = grid.size();
        vector<int> valid(size);
        for (int i = 0; i < size; ++i) {
            int j;
            for (j = size - 1; j >= 0 && grid[i][j] == 0; --j) {
            }
            valid[i] = size - 1 - j;
        }
        
        vector<int> tmp = valid;
        sort(tmp.rbegin(), tmp.rend());
        for (int i = 0; i < size; ++i) {
            if (tmp[i] < size - 1 - i) {
                return -1;
            }
        }
        
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (valid[i] < size - 1 - i) {
                int j;
                for (j = i + 1; j < size && valid[j] < size - 1 - i; ++j) {
                }
                
                int jcount = valid[j];
                valid.erase(valid.begin() + j);
                valid.insert(valid.begin() + i, jcount);
                result += j - i;
            }
        }
        return result;
    }
};
