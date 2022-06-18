class WordFilter {
public:
    WordFilter(vector<string>& words) {

        int size = words.size();
        for (int i = 0; i < size; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {

        return hashMap[prefix + "|" + suffix] - 1;
    }
    
   private:
    unordered_map<string, int> hashMap;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
