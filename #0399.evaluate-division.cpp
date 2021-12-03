class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int size = equations.size();
        for (int i = 0; i < size; i++) {
            group[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            group[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
        }

        size = queries.size();
        for (int i = 0; i < size; i++) {
            visit = false;
            helper(1,queries[i][0], queries[i][1]);
            if (!visit) {
                result.push_back(-1.0);
            }
        }
        return result;
    }

private:
    vector<double> result;
    unordered_map<string,vector<pair<string,double>>> group;
    unordered_map<string,int> visited;
    bool visit;

    void helper(double conclude,string& now,string& querie) {
        if (group.count(now) != 0 && now == querie) {
            result.push_back(conclude);
            visit = true;
        } else {
            vector<pair<string,double>>::iterator it = group[now].begin();
            while (it != group[now].end() && !visit) {
                if (visited[(*it).first] == 0) {
                    visited[(*it).first] = 1;
                    helper(conclude*((*it).second),(*it).first, querie);
                    visited[(*it).first] = 0;
                }
                it++;
            }
        }
    }
};
