class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long sum = 0;
        for (auto it : chalk) {
            sum += it;
        }

        long long q = k % sum;
        long long psum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            if (psum > q) {
                return i;
            }

            psum += chalk[i];
            if (psum > q) {
                return i;
            }
        }
        return -1;
    }
};
