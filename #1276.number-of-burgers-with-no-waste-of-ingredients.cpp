class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {

        if (tomatoSlices % 2 != 0) {
            return {};
        }
        if (tomatoSlices > cheeseSlices * 4  || cheeseSlices * 2 > tomatoSlices) {
            return {};
        }

        int tomato = cheeseSlices;
        int difference = tomatoSlices - cheeseSlices * 2;
        vector<int> result;
        if (difference == 0) {
            result.push_back(0);
            result.push_back(tomato);
            return result;
        }

        int divide = difference / 2;
        result.push_back(divide);
        result.push_back(tomato - divide);
        return result;
    }
};
