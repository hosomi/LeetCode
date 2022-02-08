class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        int size = satisfaction.size();
        std::sort(satisfaction.rbegin(), satisfaction.rend());
        int result = 0;
        int sum = 0;
        for (int i = 0; i < size && satisfaction[i] + sum > 0; i++) {
            sum += satisfaction[i];
            result += sum;
        }
        return result;
    }
};
