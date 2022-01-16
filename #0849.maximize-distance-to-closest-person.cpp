class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int size = seats.size();
        vector<int> reserved;
        int result = 1;

        for (int i = 0; i < size; i++) {
            if (seats[i] == 1) {
                reserved.push_back(i);
            }
        }

        int sizeReserved = reserved.size();
        if (sizeReserved == 1) {
            return std::max(size -1 -reserved[0], reserved[0]);
        }

        result = reserved[0];
        for (int i = 1; i < sizeReserved; i++) {
            result = std::max(result, (reserved[i] - reserved[i-1]) / 2);
        }
        result = std::max(result, size -1 -reserved[sizeReserved -1]);
        return result;
    }
};
