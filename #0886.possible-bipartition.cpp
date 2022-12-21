class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> color(2005, -1);
        vector<int> v[2005];
        for (auto d: dislikes) {
            v[d[0]].push_back(d[1]);
            v[d[1]].push_back(d[0]);
        }

	    for (int i = 1; i <= n; i++) {

            if (color[i] != -1) {
                continue;
            }
    
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j: v[u]) {
                    if (color[j] == -1) {
                        color[j] = color[u] ^ 1;
                        q.push(j);
                    } else {
                        if (color[u] == color[j]) {
                            return false;
                        }
                    }
                }
            }
        }
	    return true;
    }
};
