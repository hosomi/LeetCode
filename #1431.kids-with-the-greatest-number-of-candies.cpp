class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int size = candies.size();
        int maxCandy = *std::max_element(candies.begin(), candies.end());
        vector<bool> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = (maxCandy - candies[i] <= extraCandies);
        }
        return result;
    }
};
