class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {

        vector<int> v;
        isSplitIntoFibonacci(v, num, num.length(), 0, 0, 0);
        return v;
    }

private:
    bool isSplitIntoFibonacci(
        vector<int> &v,
        string num,
        int length,
        int index,
        long long sum,
        int prev) {

        if (index == length) {
            return v.size() >= 3;
        }

        long long cur = 0;
        for (int i = index; i < length; ++i) {
            if (i > index && num[index]=='0') {
                break;
            }

            cur = cur * 10 + num[i] - '0';
            if (cur > INT_MAX) {
                break;
            }

            if (v.size() >= 2) {
                if (cur<sum) {
                    continue;
                }
                
                if (cur>sum) {
                    break;
                }
            }

            v.push_back(cur);
            if (isSplitIntoFibonacci(v, num, length, i + 1, prev + cur, cur)) {
                return true;
            }
            v.pop_back();
        }
        return false;
    }
};
