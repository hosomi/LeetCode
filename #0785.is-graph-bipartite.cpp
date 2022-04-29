class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int size = graph.size();
        vector<int> color(size, 0);
        for(int i = 0; i < size; i++) {
            if (color[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int parent = q.front();
                q.pop();
                for (int child:graph[parent]) {
                    if (color[child] == 0) {
                        color[child]=-color[parent];
                        q.push(child);
                    } else {
                        if (color[parent]==color[child]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
