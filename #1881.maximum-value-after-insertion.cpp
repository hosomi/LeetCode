class Solution {
public:
    string maxValue(string n, int x) {

        int size = n.size();
        string b = to_string(x);
        int index;
        if (n[0]=='-') {
            for (int i = 1; i < size; i++) {
                if (n[i] > b[0]) {
                    index = i;
                    break;
                }
                    
            }
        } else {
            for (int i = 0; i < size; i++) {
                if (n[i] < b[0]) {
                    index = i;
                    break;
                }
            }
        }
        string result = n.substr(0, index);
        result += b;
        result += n.substr(index);
        return result;
    }
};
