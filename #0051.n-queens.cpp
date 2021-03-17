class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        this->index = n;
        vector<string> cursor(n, string(n, '.'));
        vector<vector<string>> result;
        vector<int> used(n + 2*n-1 + 2*n-1, false);
        updateBoard(used, 0, cursor, result);
        return result;
    }

    int index;
    void updateBoard(vector<int>& used, int index, 
                   vector<string>& cursor,
                   vector<vector<string>>& result) {

        if (index == this->index) {
            result.push_back(cursor);
        } else {
            for (int c = 0; c < this->index; ++c) {
                if(!used[c] && !used[this->index+index-c+this->index-1] && !used[this->index+2*this->index-1+index+c]) {
                    cursor[index][c] = 'Q';
                    used[c] = used[this->index+index-c+this->index-1] = used[this->index+2*this->index-1+index+c] = true;
                    
                    updateBoard(used, index+1, cursor, result);
                    
                    used[c] = used[this->index+index-c+this->index-1] = used[this->index+2*this->index-1+index+c] = false;
                    cursor[index][c] = '.';
                }
            }
        }
    };
};
