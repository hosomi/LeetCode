class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<double> s;
        vector<vector<int>> v;
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (v[i][0] == v[j][0] && v[i][1] == v[j][1]) {
                    return false;
                }

                double x = std::sqrt((v[i][0] - v[j][0]) 
                    * (v[i][0]-v[j][0]) + (v[i][1]-v[j][1]) 
                    * (v[i][1]-v[j][1]));
                s.insert(x);
            }
        }
        return s.size()==2;
    }
};
