class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> wordcounter;
        vector<int> result;
        for(string& word : words){
            ++wordcounter[word];
        }

        int ssize = s.size();
        int wsize = words.size();
        int vsize = words[0].size();
        for (int i = 0; i + wsize * vsize - 1 < ssize; ++i) {

            int j = 0;
            unordered_map<string, int> word2visited;
            for (; j < wsize; ++j) {
                string subs(s.begin()+i+j*vsize, s.begin()+i+(j+1)*vsize);
                if (wordcounter.find(subs) == wordcounter.end()) {
                    break;
                }

                ++word2visited[subs];
                if (word2visited[subs] > wordcounter[subs]) {
                    break;
                }
            }
            
            if (j == wsize) {
                result.push_back(i);
            }
        }

        return result;
    }
};
