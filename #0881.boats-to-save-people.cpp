class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int size = people.size();
        int i = 0;
        int j = size - 1;
        std::sort(people.begin(), people.end());
        int result = 0;
        while (i <= j) {
            result++;
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
        }
        return result;
    }
};
