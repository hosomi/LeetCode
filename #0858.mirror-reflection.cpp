class Solution {
public:
    int mirrorReflection(int p, int q) {

        if (q == 0) {
            return 0;
        }
        
        int pos = 0;
        bool isUp = false;
        do {
            isUp = !isUp;
            pos += p;
        } while (pos % q > 0);
        
        if (isUp) {
            return (pos / q) % 2 == 0 ? 2 : 1;
        }
    
        return 0;
    }
};
