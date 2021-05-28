class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        std::unordered_set<string> us;
        std::unordered_map<string, int> um;
        std::queue<string> q;

        um[beginWord] = 1;
        q.push(beginWord);
        for (auto word: wordList) {
            us.insert(word);
        }

        string s;
        while (q.size()) {
            auto f = q.front();
            q.pop();
            s = f;
            for (int i = 0; i < f.size(); i ++) {
                f = s;
                for (char j = 'a'; j <= 'z'; j ++) {
                    if (s[i] != j) {
                        f[i] = j;
                        if (us.count(f) && um.count(f) == 0) {
                            um[f] = um[s] + 1;
                            if (f == endWord) {
                                return um[f];
                            }
                            q.push(f);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
