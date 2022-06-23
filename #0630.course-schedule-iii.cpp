class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        std::sort(courses.begin(), courses.end(), [&] (
            vector<int> &begin , vector<int> &end) {
                return begin[1] < end[1];
        });
        
        int top = 0;
        priority_queue<int>pq;
        for (auto course : courses) {
            if (top + course[0] <= course[1]) { 
                pq.push(course[0]);
                top += course[0];
            } else if (!pq.empty() && pq.top() > course[0]) {
                int z = pq.top();
                pq.pop();
                top -= z;
                pq.push(course[0]);
                top += course[0];    
            }
        }
        return pq.size();
    }
};
