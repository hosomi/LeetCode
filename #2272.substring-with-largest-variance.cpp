class Solution {
public:
    int largestVariance(string s) {
        
        int size = s.size();
        int result = 0;
        for(int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                char chi = 'a' + i;
                char chj = 'a' + j;
                int high = 0;
                int low = 0;
                int tempans = 0;
                int restart = 0;
                for (int k = 0; k < size; k++) {
                    if (s[k] == chi) {
                        high++;
                        if (low == 0 && restart == 1) {
                            tempans = std::max(tempans, high - 1);
                        }

                        if (low >= high && low != 0) {
                            restart = 1;
                            high = 1;
                            low = 0;
                        } else if (low != 0) {
                            tempans = std::max(tempans, high - low);
                        }
                    } else if (s[k] == chj) {
                        low++;
                        if (low != 0) {
                            tempans = std::max(tempans, high - low);
                        }
                    }
                }
                result = std::max(result, tempans);
            } 
        }
        return result;
    }
};
