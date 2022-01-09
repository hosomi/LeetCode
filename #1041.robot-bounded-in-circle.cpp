class Solution {
public:
    bool isRobotBounded(string instructions) {

        vector<int> stand = {0, 0};
        vector<vector<int>> stands = {{0,1}, {-1,0}, {0,-1}, {1,0}};
        int index = 0;
        for (char c : instructions) {
            switch(c){
                case 'G':
                    stand[0] += stands[index][0];
                    stand[1] += stands[index][1];
                    break;
                case 'L':
                    index = (index + 1) % 4;
                    break;
                case 'R':
                    index = (index + 4 - 1) % 4;
                    break;
            }
        }
        return (stand[0] == 0 && stand[1] == 0) || (index != 0);
    }
};
