class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int size = obstacles.size();
        vector<int> v;
        vector<int> result;
        for (int i = 0; i < size; i++) {
            auto it = upper_bound(v.begin(), v.end(), obstacles[i]);
            if (it == v.end()) {
                v.push_back(obstacles[i]), result.push_back(v.size());
            } else {
                *it = obstacles[i];
                result.push_back(it - v.begin() + 1);
            }
        }
        return result;
    }
};
