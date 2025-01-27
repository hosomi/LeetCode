class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        for (vector<int> v : prerequisites){
            graph[v[0]][v[1]] = true;
        }
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j< numCourses;j++) {
                    graph[i][j] = graph[i][j]||(graph[i][k] && graph[k][j]);
                }
            }
        }
        vector<bool> ans;
        for (vector<int> v : queries) {
            ans.push_back(graph[v[0]][v[1]]);
        }
        return ans;
    }
};
