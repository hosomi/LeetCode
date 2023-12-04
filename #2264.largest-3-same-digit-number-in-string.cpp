class Solution {
public:
    string largestGoodInteger(string num) {

        char c{};
        for (int i{2}; i < num.size(); ++i) {
            if (num[i] == num[i-1] && num[i-1] == num[i-2]) {
                c = std::max(c, num[i]);
            }
        }
        return c ? string(3, c) : "";
    }
};
