class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> result(num_people);
        for (int i = 1; candies > 0; i++) {
            result[(i-1) % num_people] += std::min(candies, i);
            candies = std::max(0, candies - i);
        }
        return result;
    }
};
