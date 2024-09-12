class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            int flag = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if (allowed.find(words[i][j]) == string::npos) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
