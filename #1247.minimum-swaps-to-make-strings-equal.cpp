class Solution {
public:
    int minimumSwap(string s1, string s2) {

        int size = s1.size();
        int x = 0;
        int y = 0;
        for (int i = 0; i < size; i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            
            if (s1[i] == 'x') {
                x++;
            } else {
                y++;
            }
        }
        
        int result = x / 2 + y / 2;
        x %= 2;
        y %= 2;
        if (x == 1 && y == 1) {
            result += 2;
            x--;
            y--;
        }
        return x == 0 && y == 0 ? result : -1;
    }
};
