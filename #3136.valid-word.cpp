class Solution {
public:
    bool isValid(string word) {

        int n = word.size();
        if (n < 3) {
            return false;
        }

        int v = 0;
        int c = 0 ;
        for (auto i : word) {
            if (isalpha(i)) {
                if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                    v++;
                } else if (i == 'A' || i == 'E' || i =='I' || i =='O' || i =='U') {
                    v++;
                } else {
                    c++;
                }
            }

            if (!(isalpha(i) || isdigit(i))) {
                return 0;
            }
        }

        if (v >= 1 && c >= 1) {
            return 1;
        }
        return 0;
    }
};
