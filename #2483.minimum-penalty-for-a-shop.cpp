class Solution {
public:
    int bestClosingTime(string customers) {

        int size = customers.size();
        int curr = 0;
        int max = 0;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (customers[i] == 'Y') {
                curr++;
            } else{
                curr--;
            }

            if (curr > max) {
                result = i + 1;
                max = curr;
            }
        }
        return result;
    }
};
