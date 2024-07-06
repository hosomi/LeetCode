class Solution {
public:
    int passThePillow(int n, int time) {

        int k = time % (n - 1);
        return (time / (n - 1)) % 2 ? n - k : k + 1;
    }
};
