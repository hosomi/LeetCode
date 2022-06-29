class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        int size = people.size();
        if (size == 0) {
            return vector<vector<int>>();
        }

        std::sort(people.begin(), people.end(), [] (
            vector<int>& left, vector<int>& right) {
                return left[0] == right[0] ?
                    left[1] < right[1] : left[0] > right[0];
            }
        );
        
        int p = people[0][0];
        vector<vector<int>> result;
        for (int i = 0; i < size; i++) {
            if (people[i][0] == p) {
                result.push_back(people[i]);
            } else {
                result.insert(result.begin() + people[i][1], people[i]);
            }
        }
        return result;
    }
};
