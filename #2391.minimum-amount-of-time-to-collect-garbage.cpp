class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int size = garbage.size();
        int lastg = 0;
        int lastm = 0;
        int lastp = 0;
        int result = 0;
        for (int i=0; i < size; i++) {
            for (auto j : garbage[i]) {
                result ++;
                if (j == 'M') {
                    lastm = i;
                } else if (j == 'P') {
                    lastp = i;
                } else if (j == 'G') {
                    lastg = i;
                }
            }   
        }

        size = travel.size();
        for (int i = 0; i < size; i++) {
            if (i < lastg) {
                result += travel[i];
            }

            if (i < lastp) {
                result += travel[i];
            }

            if (i < lastm) {
                result += travel[i];
            }
        }
        return result;
    }
};
