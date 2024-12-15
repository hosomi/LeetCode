class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int i;
        double diff;
        priority_queue<pair<double, int>> pq;
        for (i = 0; i < classes.size(); i++) {
            diff = (double)(classes[i][0] + 1)
                / (classes[i][1] + 1)
                - (double)(classes[i][0])
                / classes[i][1];
            pq.push(make_pair(diff, i));
        }

        while (extraStudents--) {
            i = pq.top().second;
            pq.pop();
            classes[i][0] += 1;
            classes[i][1] += 1;

            diff = (double)(classes[i][0] + 1)
                / (classes[i][1] + 1)
                - (double)(classes[i][0])
                / classes[i][1];
            pq.push(make_pair(diff, i));
        }

        double avg;
        double result = 0;
        for (i = 0; i < classes.size(); i++) {
            avg = (double)(classes[i][0]) / classes[i][1];
            result += avg;
        }
        return result / classes.size();
    }
};
