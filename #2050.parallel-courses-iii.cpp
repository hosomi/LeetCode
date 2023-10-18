class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> graph(n + 1);
        vector<int> vindex(n + 1, 0);
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int next = relation[1];
            graph[prevCourse].push_back(next);
            vindex[next]++;
        }
        
        queue<int> q;
        vector<int> vstart(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (vindex[i] == 0) {
                q.push(i);
                vstart[i] = 0;
            }
        }
        
        int result = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result = std::max(result, vstart[course] + time[course - 1]);
            for (int next : graph[course]) {
                vindex[next]--;
                vstart[next] = std::max(vstart[next],
                  vstart[course] + time[course - 1]);
                
                if (vindex[next] == 0) {
                    q.push(next);
                }
            }
        }
        return result;
    }
};
