class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int base = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        while (std::pow(base, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};
