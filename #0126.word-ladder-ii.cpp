class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> graph;
        if (words.find(endWord) == words.end()) {
            return vector<vector<string>>();
        }

        bool foundEnd = false;
        queue<string> q1, q2;
        unordered_set<string> visited1, visited2;
        queue<string> qnext;
        bool reversed = false;
        q1.push(beginWord);
        q2.push(endWord);
        visited1.insert(beginWord);
        visited2.insert(endWord);
        while (!q1.empty() && !q2.empty() && !foundEnd) {
            if (q1.size() < q2.size()) {
                foundEnd = visitLevel(words, graph, q1, visited1, visited2, false);
            } else {
                foundEnd = visitLevel(words, graph, q2, visited2, visited1, true);
            }
        }

        vector<string> path = {beginWord};
        vector<vector<string>> paths;
        backtrack(beginWord, endWord, graph, path, paths);
        return paths;
    }

private:
    void backtrack(string cur, string& endWord, unordered_map<string, unordered_set<string>>& graph,
        vector<string>& path, vector<vector<string>>& paths) {

        if (cur == endWord) {
            paths.push_back(path);
        } else {
            for (const string& nei : graph[cur]) {
                path.push_back(nei);
                backtrack(nei, endWord, graph, path, paths);
                path.pop_back();
            }
        }
    };
    
    bool visitLevel(unordered_set<string>& words, unordered_map<string, unordered_set<string>>& graph,
                      queue<string>& q, unordered_set<string>& visited, unordered_set<string>& visited_other, bool reversed) {

        int levelSize = q.size();
        bool foundEnd = false;
        unordered_set<string> visiting;
        string cur;
        string nei;
        char oldC;
        while (levelSize-- > 0) {
            cur = q.front(); q.pop();
            nei = cur;
            for (int i = 0; i < cur.size(); ++i) {
                oldC = nei[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == oldC) {
                        continue;
                    }
                    nei[i] = c;

                    if (words.find(nei) != words.end()) {
                        if (visited_other.find(nei) != visited_other.end()) {
                            foundEnd = true;
                        }

                        if (visited.find(nei) == visited.end()) {
                            visiting.insert(nei);
                            q.push(nei);

                            if (!reversed) {
                                graph[cur].insert(nei);
                            } else {
                                graph[nei].insert(cur);
                            }
                        }
                    }

                }
                nei[i] = oldC;
            }
        }

        visited.insert(visiting.begin(), visiting.end());
        return foundEnd;
    };
};
