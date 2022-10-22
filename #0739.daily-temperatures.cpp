class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int size = temperatures.size();
        vector<int> result(size);
        stack<int> stk;
        for (int i = size -1; i >= 0; i--) {
            while (!stk.empty() &&
                  temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            result[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return result;
    }
};
