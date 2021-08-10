class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> v1(numCourses, vector<int>());
        vector<int> v2(numCourses);
        for (auto v : prerequisites) {
            v1[v[1]].push_back(v[0]);
            ++v2[v[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (v2[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto v : v1[i]) {
                --v2[v];
                if (v2[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (v2[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
