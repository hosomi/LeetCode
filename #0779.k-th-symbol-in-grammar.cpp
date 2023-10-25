class Solution {
public:
    int kthGrammar(int n, int k) {
        return std::bitset<32>(k-1).count() & 1;
    }
};
