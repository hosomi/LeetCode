class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flips = 0;
        for (int i = 0; 1 << i <= std::max(std::max(a, b), c); i++) {
            int bit = 1 << i;
            int abit = a & bit ? 1 : 0;
            int bbit = b & bit ? 1 : 0;
            int cbit = c & bit ? 1 : 0;
            if (!(abit | bbit) && cbit) {
                flips++;
            } else if ((abit & bbit) && !cbit) {
                flips += 2;
            } else if ((abit ^ bbit) && !cbit) {
                flips++;
            }
        }
        return flips;
    }
};
