class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        
        int n = 0;
        int moda_count = 0;
        int moda;
        int mini = INT_MAX;
        int maxi = 0;
        long sum = 0;
        for (int i = 0; i != 256; i++) {
            if (count[i]) {
                n += count[i];
                if (moda_count < count[i]) {
                    moda_count = count[i], moda = i;
                }
                mini = min(mini, i);
                maxi = max(maxi, i);
                sum += long(count[i])*i;
            }
        }

        int lim = (n+1)>>1;
        int i = 0; 
        while(lim > count[i]) {
            lim -= count[i++];
        }

        double midi = i;
        if (lim == count[i] && n%2 == 0) {
            while(count[++i] == 0);
            midi = (midi + i)/2;
        }
            
        return {double(mini), double(maxi), double(sum) / n, midi, double(moda)};
    }
};
