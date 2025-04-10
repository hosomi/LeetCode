class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        return countPowerfulInt(finish, limit, s)
            - countPowerfulInt(start - 1, limit, s);
    }

private:
    long long countPowerfulInt(long long num, int limit, string& s) {

        string num_str = to_string(num);
        if (num_str.size() < s.size()) {
            return 0;
        }

        string head = num_str.substr(0, num_str.size() - s.size());
        string tail = num_str.substr(num_str.size() - s.size());
        char limit_char = '0' + limit;
        long long head_num = 0;
        bool exceeded = false;
        for (int i = 0; i < head.size(); i++) {
            if (head[i] > limit_char) {
                exceeded = true;
            }
            head_num = head_num * (limit + 1) + (exceeded ? limit : head[i] - '0');
        }

        return head_num + (!exceeded && getStoll(tail) < getStoll(s) ? 0 : 1);
    }

    long long getStoll(const string& s) {
        return s.empty() ? 0 : stoll(s);
    }
};
