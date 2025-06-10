class Solution {
public:
    int maxDifference(string s) {

        vector<int> mpp(26);
        int max = 0;
        int min = s.size();
        for (char c : s) mpp[c - 'a']++;
        for (int i = 0 ; i < 26; i++) {
            if (mpp[i] % 2 != 0) {
                max = std::max(max, mpp[i]);
            }
            if (mpp[i] % 2 == 0 && mpp[i] > 0) {
                min = std::min(min, mpp[i]);
            }
        } 
        return max - min;
    }
};
