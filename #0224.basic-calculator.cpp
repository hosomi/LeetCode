class Solution {
public:
    int calculate(string s) {

        stack<int> sr;
        stack<int> si;
        int r = 0;
        int i = 1;
        int ir = 0;
        
        for (char c : s){
            if (c >= '0' && c <= '9') {
                r = r * 10 + (c - '0');
            } else if (c == '+') {
                ir += i * r;
                r = 0;
                i = 1;
            } else if(c == '-') {
                ir += i * r;
                r = 0;
                i = -1;
            } else if (c == '(') {
                sr.push(ir);
                si.push(i);
                ir = 0;
                i = 1;
            } else if (c == ')') {
                ir += i * r;
                ir *= si.top(); si.pop();
                ir += sr.top(); sr.pop();
                r = 0;
            }
        }

        return ir + i * r;
    }
};
