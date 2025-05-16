class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        unordered_map<string, array<int, 4>> mp;
        int N = words.size();
        int maxLen = 0;
        int targeIdx = 0;
        for (int i = 0; i < N; i++) {
            int currMax = 0;
            int currIdx = -1;
            for (int j = 0; j < words[i].size(); j++) {
                for (int c = 0; c < 26; c++) {
                    string s = words[i];
                    s[j] = c + 'a';
                    if (mp.count(s) && mp[s][3] != groups[i] && mp[s][0] > currMax) {
                        currMax = mp[s][0];
                        currIdx = mp[s][1];
                    }
                }
            }

            mp[words[i]] = {currMax + 1, i, currIdx, groups[i]};
            if (maxLen < currMax + 1) {
                maxLen = currMax + 1;
                targeIdx = i;
            }
        }

        vector<string> res(maxLen);
        while(maxLen) {
            res[--maxLen] = words[targeIdx];
            targeIdx = mp[words[targeIdx]][2];
        }
        return res;
    }
};
