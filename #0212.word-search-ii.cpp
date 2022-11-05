class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for (auto word:words) {
            addWord(word);
        }
        
        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (root->child[board[i][j]-'a'] != NULL) {
                    checkWord(root->child[board[i][j]-'a'], board, i, j, result, "");
                }
            }
        }
        return result;
    }
    

    void addWord(string word) {
        TrieNode* curr=root;
        for (int i = 0; i < word.length(); ++i) {
            int ind=word[i]-'a';
            if (curr->child[ind]==NULL) {
                curr->child[ind]=getNode();
            }
            curr=curr->child[ind];
        }
        curr->endsHere=1;
    }

private:
    struct TrieNode {
        int endsHere;
        TrieNode* child[26];
    };
     
    TrieNode* root = getNode();
    vector<vector<int>> offset = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    TrieNode* getNode() {

        TrieNode* newNode=new TrieNode;
        newNode->endsHere=0;
        for (int i = 0; i < 26; ++i) {
            newNode->child[i]=NULL;
        }
        return newNode;
    }

    void checkWord(TrieNode* curr, vector<vector<char>>& board,
                   int i,int j,vector<string>& result,string s) {
        
        s.push_back(board[i][j]);
        if (curr->endsHere > 0) {
            result.push_back(s);
            curr->endsHere -= 1;
        }

        char orig = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int x = offset[k][0]+i;
            int y = offset[k][1]+j;
            
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()
               || board[x][y] == '#' || curr->child[board[x][y] - 'a'] == NULL) {
                continue;
            }
            checkWord(curr->child[board[x][y]-'a'], board, x, y, result, s);
        }
        board[i][j] = orig;
    }
};
