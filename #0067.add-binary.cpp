class Solution {
public:
    string addBinary(string a, string b) {

        string result;
        int work = 0;
        int asize = a.size();
        int bsize = b.size();
        int max = std::max(asize, bsize);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        for (int i = 0; i < max; i++) {
            if (i < asize) {
                work += (a[i] - '0');
            }

            if (i < bsize) {
                work += (b[i] - '0');
            }
            result.push_back(work % 2 + '0');
            work /= 2; 
        }

        if (work) {
            result.push_back('1');
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
