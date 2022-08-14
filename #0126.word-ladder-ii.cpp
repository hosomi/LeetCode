class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        for (string node : wordList) {
            dist[node] = INT_MAX;
            parent[node] = {};
        }

        parent[beginWord] = { "root" };
        queue<string> q;
        dist[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) {
            string par = q.front();
            q.pop();
            if (par == endWord) {
                break;
            }

            int size = par.size();
            for(int i = 0; i < size; i++) {
                string pref = "" , suff = "";
                if (i) {
                    pref = par.substr(0,i);
                }

                if (i < size - 1) {
                    suff = par.substr(i + 1);
                }
                
                string child = pref + '$'+suff;
                int pos = pref.size();
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c != par[i]) {
                        child[pos] = c;
                        if (dist.count(child)) {
                            if (dist[child] > 1 + dist[par]) {
                                dist[child] =  1 + dist[par];
                                parent[child].clear();
                                parent[child].push_back(par);
                                q.push(child);
                            } else if(dist[child] == 1 + dist[par]) {
                                parent[child].push_back(par);
                            }
                        }
                    }
                }
            }
        }

        vector<string> path;
        pathfinder(endWord, path);
        int size = result.size();
        for (int i=0; i < size; i++) {
             std::reverse(result[i].begin(), result[i].end());
        }
        return result;
    }

private:
    map<string,vector<string>> parent;
    unordered_map<string,int> dist;
    vector<vector<string>> result;

    void pathfinder(string par,vector<string>&path) {

        if (par == "root") {
            result.push_back(path); 
            return;
        }

        for (string node : parent[par]) {
            path.push_back(par);
            pathfinder(node,path);
            path.pop_back();
        }
    }
};
