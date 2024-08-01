class Solution {
public:
    int countSeniors(vector<string>& details) {

        int result = 0;
        for (auto detail: details) {
            if (stoi(detail.substr(11, 2)) > 60) {
                result++;
            }
        }
        return result;
    }
};
