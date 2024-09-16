class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;
        for (auto &time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3));
            int totalMinutes = hour * 60 + minute;
            minutes.push_back(totalMinutes);
        }

        std::sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            int currentDiff = minutes[i] - minutes[i - 1];
            minDiff = min(minDiff, currentDiff);
        }

        int lastDiff = (minutes.front() + 1440) - minutes.back();
        return std::min(minDiff, lastDiff);
    }
};
