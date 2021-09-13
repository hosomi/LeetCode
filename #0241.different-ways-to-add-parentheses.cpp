class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        int length = expression.length();
        vector<int> result;
        char c;
        vector<int> left, right;
        for (int i = 0; i < length; i++) {
            c = expression[i];
            if (c != '+' && c != '-' && c != '*') {
                continue;
            }

            left = diffWaysToCompute(expression.substr(0, i));
            right = diffWaysToCompute(expression.substr(i + 1));
            for (auto l : left) {
                for (auto r : right) {
                    if (c == '+') {
                        result.push_back(l + r);
                    } else if (c == '-') {
                        result.push_back(l - r);
                    } else {
                        result.push_back(l * r);
                    }
                }
            }
        }

        if (!result.empty()) {
            return result;
        }

        int i = 0;
        for(auto e : expression){
            i = i * 10 + (e - '0');
        }
        result.push_back(i);
        return result;
    }
};
