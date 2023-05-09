class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int count = 1;
        string temp = a;
        while (a.find(b) == string::npos) {
            a += temp;
            count++;
            if (a.size() > b.size() + temp.size()) {
                break;
            }
        }
        return (a.find(b) == string::npos) ? -1 : count;
    }
};
