class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

        root = new Words();
    }

    void addWord(string word) {

        Words *w = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!w->child[i]) {
                w->child[i] = new Words();
            }
            w = w->child[i];
        }

        w->isWord = true;
    }

    bool search(string word) {
        return searchWord(word, root, 0);
    }

private:

    struct Words {
    public:
        Words *child[26];
            bool isWord;
            Words() : isWord(false) {
                for (auto &a : child) {
                    a = NULL;
                }
            }
    };

    Words *root;
    
    bool searchWord(string &word, Words *w, int i) {

        if (i == word.size()) {
            return w->isWord;
        }

        if (word[i] == '.') {
            for (auto &a : w->child) {
                if (a && searchWord(word, a, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return w->child[word[i] - 'a']
                && searchWord(word, w->child[word[i] - 'a'], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
