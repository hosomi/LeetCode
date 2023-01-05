class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        vector<int> zero = {0};
        vector<int>::iterator it = find_end(bits.begin(), bits.end() - 1,
            zero.begin(), zero.end());
        if (it != bits.end() - 1) {
            cout << bits.end() - it - 1 << endl;
            return (bits.end() - it - 1) % 2 != 0;
        }
        
        return bits.size() % 2 != 0;
    }
};
