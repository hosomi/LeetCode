class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int size = meetings.size();
        sort(meetings.begin() , meetings.end());
        map<long long,long long> rooms;
        for (int j = 0; j < n; j++) {
            rooms[j] = 0;
        }

        map<long long,long long>use;
        for (int i = 0; i < size; i++) {
            int start_time = meetings[i][0];
            int end_time = meetings[i][1];
            int duration = end_time - start_time;
            bool done = false;
            for (int j = 0; j < n; j++) {
                if (start_time >= rooms[j]) {
                    rooms[j] = end_time;
                    use[j]++;
                    done = true;
                    break;
                }
            }

            if (!done) {
                long long early = LONG_MAX;
                for (int j = 0; j < n; j++) {
                    early = min(early , rooms[j]);
                }

                for (int j = 0 ; j < n; j++) {
                    if (rooms[j] == early) {
                        rooms[j] += duration;
                        use[j]++;
                        break;
                    }
                }
            }
        }

        long long max = 0;
        for (int j = 0; j < n; j++) {
            max = std::max(max , use[j]);
        }

        long long result;
        for (int j = 0; j < n; j++) {
            if (use[j] == max) {
                result = j;
                break;
            }
        }
        return result;
    }
};
