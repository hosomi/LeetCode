class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int result = 0;
        heights.push_back(0);
        int index;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                index = st.top();
                st.pop();
                result = std::max(result, heights[index] * (st.empty() ? i : (i- 1 - st.top())));
            }
            st.push(i);
        }
        return result;
    }
};
