class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int size = arr.size();
        int modulo = 1e9+7;
        vector<int> left(size), right(size);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) { 
                st.pop();
            }
 
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        
        while (!st.empty()) {
            st.pop();
        }

        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) { 
                st.pop();
            }
            
            right[i] = st.empty() ? size - i : st.top() - i; 
            st.push(i);
        }
        
        int result = 0;
        for (int i = 0; i < size; i++) {
            long long prod = (left[i] * right[i]) % modulo;
            prod = (prod * arr[i]) % modulo;
            result = (result + prod) % modulo;
        }
        return result % modulo;
    }
};
