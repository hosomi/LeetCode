class Solution {
public:
    int countHomogenous(string s) {

        int size = s.size();
        int counter = 1;
        int result = size;
        for (int i = 1; i < size; i++) {
            if (s[i] == s[i - 1]) {
                result = (result + counter) % 1000000007;
                counter++;
            } else {
                counter = 1;
            }
        }
        return result;
    }
};
