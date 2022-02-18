class Solution {
public:
    string removeKdigits(string num, int k) {

        int size = num.size();
        if (k >= size) {
            return "0";
        }

        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (k > 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k-- > 0) {
            st.pop();
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        std::reverse(result.begin(), result.end());
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1);
        }
        return result;
    }
};
