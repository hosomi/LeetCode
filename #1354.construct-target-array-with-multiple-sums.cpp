class Solution {
public:
    bool isPossible(vector<int>& target) {

        priority_queue<int> q(begin(target), end(target));
        long sum = accumulate(begin(target), end(target), 0LL);
        while (true) {
            int top = q.top();
            q.pop();
            sum -= top;
            if (top == 1 || sum == 1) {
                return true;
            }

            if (top < sum || sum == 0 || top % sum == 0) {
                return false;
            }

            top %= sum;
            sum += top;
            q.push(top);
        }
        return true;
    }
};
