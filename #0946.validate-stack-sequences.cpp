class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        int size = pushed.size();
        stack<int> stk;
        int i = 0;
        for (int p : pushed) {
            stk.push(p);
            while (!stk.empty() && i < size && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        return i == size;
    }
};
