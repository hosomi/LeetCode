class Solution {
public:
    string decodeString(string s) {

        stack<int> nums;
        stack<string> temp;
        string result = "";
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (std::isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if( isalpha(s[i])) {
                result += s[i];
            } else if(s[i] == '[') {
                nums.push(num);
                num = 0;
                temp.push(result);
                result = "";
            } else if(s[i]==']') {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; j++) {
                    temp.top() += result;
                }
                result = temp.top();
                temp.pop();
            }
        }
        return result;
    }
};
