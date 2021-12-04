class StreamChecker {
    struct Node {
        Node *next[26];
        Node *fail;
        bool isWord;
        Node() {
            memset(next, NULL, sizeof(next));
            fail = NULL;
            isWord = false;
        }
    };

public:
    StreamChecker(vector<string>& words) {

        root = new Node();
        for (auto &word : words) {
            insert(word);
        }
        stream();
        now = root;
    }
    

    bool query(char letter) {

        while (now != root && now->next[letter - 'a'] == NULL) {
            now = now->fail;
        }

        if (now->next[letter - 'a']) {
            now = now->next[letter - 'a'];
        }

        return now->isWord;
    }

private:
    Node *root;
    Node *now;

    void insert(string &word) {
        Node *p = root;
        for (auto &c : word) {
            if (p->next[c - 'a'] == NULL) {
                p->next[c - 'a'] = new Node();
            }
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }

    void stream() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *start = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (start->next[i] != NULL) {
                    Node *fail = start->fail;
                    while (fail != NULL && fail->next[i] == NULL) {
                        fail = fail->fail;
                    }

                    if (fail != NULL) {
                        start->next[i]->fail = fail->next[i];
                        start->next[i]->isWord |= fail->next[i]->isWord;
                    } else {
                        start->next[i]->fail = root;
                    }
                    q.push(start->next[i]);
                }
            }
        }
        root->fail = root;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
