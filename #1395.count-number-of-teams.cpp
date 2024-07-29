class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            int lless = 0;
            int lgreater = 0;
            int rless = 0;
            int rgreater = 0;  
            for (int j = 0; j < i; j++) {
                if (rating[j] > rating[i]) {
                    lgreater++;
                } else {
                    lless++;
                }
            }

            for (int j = i + 1; j < n; j++) {
                if (rating[j] > rating[i]) {
                    rgreater++;
                } else {
                    rless++;
                }
            }
            count += lless * rgreater + lgreater * rless;
        }
        return count;
    }
};
