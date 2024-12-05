class Solution {
public:
    bool canChange(string start, string target) {

        int i = 0;
        int j = 0;
        int s = start.size();
        int t = target.size();
        while (i < s || j < t) {
            while(i < s && start[i] == '_') {
                ++i;
            }
            while(j < t && target[j] == '_') {
                ++j;
            }

            if (start[i] != target[j]) {
                return false;
            }
            if (i < j && target[j] != 'R') {
                return false;
            }
            if (i > j && start[i] != 'L') {
                return false;
            }
            ++j;
            ++i;
        }
        return true;
    }
};
