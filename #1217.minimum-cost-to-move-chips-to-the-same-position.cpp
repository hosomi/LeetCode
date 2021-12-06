class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {

        int odd = 0;
        int even = 0;
        for(int chip : position){
            if(chip % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
        return std::min(even, odd);
    }
};
