class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {

        int size = s.size();
        vector<int> v[26];
        for (int i = 0; i < size; i++) {
            v[s[i] - 'a'].push_back(i);
        }

        for (int i = 0 ; i < 26 ; i++) {
            if (v[i].size() == 2) {
                if (distance[i] != v[i][1] - v[i][0] - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
