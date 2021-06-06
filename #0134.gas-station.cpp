class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int size = gas.size();
        int total = 0;
        for (int i = 0; i < size; ++i) {
            total += gas[i] - cost[i];
        }
        if (total < 0) {
            return -1;
        }

        int result = 0;
        int negative = 0;
        for (int i = 0; i < size; ++i) {
            negative += gas[i] - cost[i];
            if (negative < 0) {
                result = i + 1;
                negative = 0;
            }
        }
        return result;
    }
};
