class Solution {
public:
    string predictPartyVictory(string senate) {

        int size = senate.size();
        queue<int> q1;
        queue<int> q2;
        for (int i = 0; i < size; i++) {
            senate[i] == 'R' ? q1.push(i) : q2.push(i);
        }
    
        int i;
        int j;
        while (!q1.empty() && !q2.empty()) {
            i = q1.front();
            j = q2.front();
            q1.pop();
            q2.pop();
            if (i < j) {
                q1.push(i + size);
            } else {
                q2.push(j + size);
            }
        }
        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};
