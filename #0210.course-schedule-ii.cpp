class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> numCoursesCount(numCourses, 0);
        vector<vector<int>> numCoursesCountCursor(numCourses);
        vector<int> result;
        for (vector<int>& v : prerequisites) {
            numCoursesCount[v[0]]++;
            numCoursesCountCursor[v[1]].push_back(v[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(numCoursesCount[i] == 0){
                q.push(i);
            }
        }

        int counter = prerequisites.size();
        while (!q.empty()) {
            int cursor = q.front(); q.pop();
            result.push_back(cursor);
            for (int i : numCoursesCountCursor[cursor]) {
                counter--;
                if(--numCoursesCount[i] == 0){
                    q.push(i);
                }
            }
        }

        if (counter != 0) {
            result.clear();
        }
        return result;
    }
};
