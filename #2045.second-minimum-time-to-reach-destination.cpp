class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        unordered_map<int, unordered_set<int>> m;
        for (auto& e : edges) {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }

        queue<int> q;
        int dist[10001]{};
        int step = 2;
        int next[10001]{};
        q.push(1);
        dist[1] = 1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                int t = q.front();
                q.pop();
                
                for (int nxt : m[t]) {
                    if (dist[nxt] == step-1 || next[nxt]) {
                        next[t] = 1;
                    }
                }

                for (int nxt : m[t]) {
                    if (!dist[nxt]) {
                        q.push(nxt);
                        dist[nxt] = step;
                    }
                }
            }
            step++;
        }

        step = next[n] ? dist[n] : dist[n] + 1;

        int result = 0;
        for (int i = 0; i < step; i++) {
            result += time;
            if (i < step -1) {
                int mul = result / change;
                if (mul % 2) {
                    result = (mul + 1) * change;
                }
            }
        }
        return result;
    }
};
