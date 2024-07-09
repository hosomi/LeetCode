class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int start = 0;
        int end = 0;
        long long count = 0;
        for (long long i = 0; i < customers.size(); i++){
            start = std::max(customers[i][0], end);
            end = start + customers[i][1];
            count = count + end - customers[i][0];
        }
        return double(count) / customers.size();
    }
};
