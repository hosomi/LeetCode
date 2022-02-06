class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int size = days.size();
        vector<int> result(size);
        result[0] = std::min({costs[0], costs[1], costs[2]});
        for (int i = 1; i < size; i++) {
            int idx7 = std::upper_bound(days.begin(), days.end(), days[i]-7)-days.begin() - 1; 
            int idx30 = std::upper_bound(days.begin(), days.end(), days[i]-30)-days.begin() - 1;
            result[i] = 
                std::min({result[i-1] + costs[0],
                    (idx7 >= 0 && days[i] - days[idx7] >= 7 ? result[idx7] : 0) + costs[1],
                    (idx30 >= 0 && days[i] - days[idx30]>=30 ? result[idx30] : 0) + costs[2]
                })
            ;
        }
        return result[size - 1];
    }
};
