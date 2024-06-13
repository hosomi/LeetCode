class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int result = 0;
        for (int i = 0; i < seats.size(); i++) {
            result += std::abs(seats[i] - students[i]);
        }
        return result;
    }
};
