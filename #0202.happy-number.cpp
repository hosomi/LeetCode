class Solution {
public:
    bool isHappy(int n) {

        int i = 0;
        set<int> s;
        while (true) {
            i = 0;
            while (n > 0) {
                i += pow((n % 10), 2);
                n /= 10;
            }

            n = i;
            if (n == 1) {
                break;
            }
            
            if (s.find(n) != s.end()) {
                return false;
            }
            s.insert(n);
        }
        return true;
    }
};
