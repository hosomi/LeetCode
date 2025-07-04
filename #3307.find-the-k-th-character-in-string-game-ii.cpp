class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        unsigned long long mask = 0;
        for (int i = operations.size() - 1; i >= 0; i--) {
            mask = (mask << 1) | operations[i];
        }
        return 'a' + __builtin_popcountll((k - 1) & mask) % 26;
    }
};
