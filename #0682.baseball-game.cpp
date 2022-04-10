class Solution {
public:
    int calPoints(vector<string>& ops) {

        vector<int> result;
        for (auto o : ops) {
            if (o == "C") {
                result.pop_back();
            } else if (o == "+") {
                result.push_back(result.back() + result[result.size() -2]);
            } else if (o == "D") {
                result.push_back(2 * result.back());
            } else {
                result.push_back(std::stoi(o));
            }
        }
        return std::accumulate(result.begin(), result.end(), 0);
    }
};
