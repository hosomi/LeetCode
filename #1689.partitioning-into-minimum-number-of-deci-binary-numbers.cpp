class Solution {
public:
    int minPartitions(string n) {

        int length = n.length();
        char c = '1';
        for (int i = 0; i < length; i++) {
            if (c < n[i]) {
                c = n[i];
            }
        }
        return c - 48;
    }
};
