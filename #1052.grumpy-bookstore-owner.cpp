class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int alreadySatisfied = 0;
        int haveToSatisfy = 0;
        int maxToSatisfy = 0;
        int size = customers.size();
        for (int i = 0; i < size; ++i) {
            if (grumpy[i] == 0) {
                alreadySatisfied += customers[i];
            } else {
                haveToSatisfy += customers[i];
            }

            if (i - minutes >= 0) {
                if (grumpy[i - minutes] == 1) {
                    haveToSatisfy -= customers[i - minutes];
                }
            }
            maxToSatisfy = std::max(maxToSatisfy, haveToSatisfy);
        }
        return maxToSatisfy + alreadySatisfied;
    }
};
