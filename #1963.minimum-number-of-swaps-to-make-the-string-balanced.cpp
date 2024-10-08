class Solution {
public:
    int minSwaps(string s) {

        int size = 0;
        for (char &ch : s) {
            if (ch == '[') {
                size++;
            } else if (size) {
                size--;
            }
        }
        return (size + 1) / 2;
    }
};
