class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int j = 0;
        int l = k;
        int min = INT_MAX;
        for (int i = 0; i <= blocks.size() - k; i++) {
            string f = "";
            for (int j = i; j < k + i; j++) {
                f += blocks[j];
            }
            int c = count(f.begin(), f.end(), 'W');
            min = std::min(c, min); 
        }
        return min;
    }
};
