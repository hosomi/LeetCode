class Solution {
public:
    int reachNumber(int target) {
        
        int t = abs(target);
        int move = 0;
        int numMoves = 1;
        while (move < t) {
            move += numMoves;
            numMoves++;
        }

        numMoves--;
        if ((move - target) % 2 == 0) {
            return numMoves;
        }
        return numMoves + 1 + numMoves % 2;
    }
};
