class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        stack<int> s;
        vector<pair<int,int>> v;
        for (int i = 0; i < positions.size(); i++) {
            v.push_back({positions[i], i});
        }

        std::sort(v.begin(), v.end());

        for (int i = 0; i < positions.size(); i++) {
            if (s.empty()) {
                int index = v[i].second;
                s.push({index});
            } else {
                auto it = s.top();
                int index = v[i].second;
                if (directions[it] == 'R'
                    && directions[index]=='L') {
                    if (healths[it] == healths[index]) {
                        s.pop();
                    } else if (healths[it] > healths[index]) {
                        s.pop();
                        s.push(it);
                        healths[it]--;
                    } else {
                        s.pop();
                        healths[index]--;
                        i--;
                    }
                } else {
                    s.push(index);
                }
            }
        }

        vector<int> v2;
        while (s.size()) {
            int id = s.top();
            v2.push_back(id);
            s.pop();
        }

        std::sort(v2.begin(), v2.end());

        vector<int> results;
        for(auto i : v2){
            results.push_back(healths[i]);
        }
        return results;
    }
};
