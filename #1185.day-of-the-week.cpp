class Solution {

public:
    const vector<string> V_DAYS = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int day, int month, int year) {

        // ツェラーの公式。
        if (month < 3) {
            month += 12;
            --year;
        }
        int divide = year / 100;
        int remainder = year % 100;
        const auto& output = ((divide / 4 - 2 * divide + remainder + remainder / 4 + 13 * (month + 1) / 5 + day - 1) % 7 + 7) % 7;

        return V_DAYS[output];
    }
};
