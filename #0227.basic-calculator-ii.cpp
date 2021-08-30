class Solution {
public:
    int calculate(string s) {

        vector<int> nums;
        int cursor = 0;
        int index = 0;
        char o = '+';
        while (index < s.size()) {
            if (s[index] == ' ') {
                ++index;
                continue;
            }

            while (isdigit(s[index]) && index < s.size()) {
                cursor = cursor * 10 + (s[index++] - '0');
            }

            if (o == '+' || o == '-') {
                nums.push_back(cursor * (o == '+' ? 1 : -1));
            } else if (o == '*') {
                nums.back() *= cursor;
            } else if (o == '/') {
                nums.back() /= cursor;
            }
            cursor = 0;
            o = s[index++];
        }
        return std::accumulate(begin(nums), end(nums), 0);
    }
};
