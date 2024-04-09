class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int count = 0;
        int i = 0;
        while (tickets[k] != 0) {
            if (i == tickets.size()) {
                i = 0;
            }

            if (tickets[i] == 0) {
                i++;
                continue;
            }

            tickets[i]--;
            i++;
            count++;
        }
        return count;
    }
};
