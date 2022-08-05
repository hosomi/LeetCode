class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        if (deck.size() < 2) {
            return false;
        }

        map<int, int> m;
        for (int d : deck) {
            m[d]++;
        }
        
        int gcd = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            gcd = std::gcd(gcd, it->second);
        }
        
        if (gcd >= 2) {
            return true;
        }

        return false;
    }
};
