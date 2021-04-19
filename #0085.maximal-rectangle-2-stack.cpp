class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rowSize = matrix.size();
        if (rowSize == 0) {
            return 0;
        }

        int colSize = matrix[0].size();
        vector<int> cols(colSize + 1);
        int result = 0;
        int top;
        for (int i = 0; i < rowSize; i++) {
            stack<int> st;
            for (int j = 0; j < cols.size(); j++) {
                if (j < colSize) {
                    cols[j] = matrix[i][j] == '1' ? cols[j] + 1 : 0;
                }
                while (!st.empty() && cols[j] < cols[st.top()]) {
                    top = st.top();
                    st.pop();
                    result = std::max(result, cols[top] * (st.empty() ? j : (j - 1 - st.top())));
                }
                st.push(j);
            }
        }
        return result;
    }
};
