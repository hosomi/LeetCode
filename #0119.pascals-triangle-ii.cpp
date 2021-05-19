class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> result;
        vector<int> work;
        result.push_back(1);
        for (int i = 1; i <= rowIndex;i++) {
            work = {};
            work.push_back(1);
            for (int j = 1; j < i; j++) {
                work.push_back(result[j] + result[j-1]);
            }
            work.push_back(1);
            result = work;
        }
        return result;
    }
};
