class Solution {
public:
    bool validUtf8(vector<int>& data) {

        int size = data.size();
        for (int i = 0; i < size; ++i) {
            if (data[i] < 0b10000000) {
                continue;
            }

            int counter = 0;
            int sequence = data[i];
            for (int j = 7; j >= 1; --j) {
                if (sequence >= pow(2, j)) {
                    ++counter;
                } else {
                    break;
                }
                sequence -= pow(2, j);
            }

            if (counter == 1 || counter > 4 || counter > size - i) {
                return false;
            }

            for (int j = i + 1; j < i + counter; ++j) {
                if (data[j] > 0b10111111 || data[j] < 0b10000000) {
                    return false;
                }
            } 
            i += counter - 1;
        }
        return true;
    }
};
