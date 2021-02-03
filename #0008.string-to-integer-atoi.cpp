class Solution {
public:
    int myAtoi(string s) {

        int length = s.length();
        bool positive = true;
        int index;
        for (index = 0 ; index < length; ++index){
            if (s[index] != ' ' && s[index] != '+' && s[index] != '-' && !isdigit(s[index])) {
                return 0;
            } else if(s[index] == ' '){
                continue;
            } else if(s[index] == '+'){
                ++index;
                break;
            } else if(s[index] == '-'){
                ++index;
                positive = false;
                break;
            } else{
                break;
            }
        }

        long long result = 0;
        for (int rindex = index; rindex < length; ++rindex) {
            if (!isdigit(s[rindex])){
                break;
            }

            result = result * 10 + (positive ? (s[rindex] - '0') : -(s[rindex] - '0'));
            if (result > INT_MAX){
                return INT_MAX;
            } else if(result < INT_MIN){
                return INT_MIN;
            }
        }
        return (int) result;
    }
};
