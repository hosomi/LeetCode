class Solution {
public:
    int numRabbits(vector<int>& answers) {

        unordered_map<int,int> m;
        int res = 0;
        for (int answer : answers) {
            (m.count(answer) == 0) ? res += answer + 1 : m[answer]++;
            if (m[answer] == answer) {
                m.erase(answer);
            }
        }
        return res; 
    }
};
