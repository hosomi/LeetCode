class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int size = dist.size();
        int min = 1;
        int max = 1e7;
        int result = -1;
        while (min <= max ){
            int avg = (min + max) / 2;
            double total = 0;
            for (int i = 0; i < size -1; i++) {
                total += ceil((double)dist[i] / avg);
            }

            total += (((double)dist.back()) / avg);
            if (total > hour) {
                min = avg + 1;
            } else {
                result = avg;
                max = avg-1;
            }
        }
        return result;
    }
};
