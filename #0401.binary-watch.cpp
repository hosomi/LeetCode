class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        countDigits(0,0,0,turnedOn);
        std::sort(result.begin(), result.end());
        return result;
    }

private:
    vector<string> result;
    int d[10] = {1, 2, 4, 8, 16, 32, 60, 120, 240, 480};

    void countDigits(int k,int l,int sum, int num) {

        if (sum >= 720 || l <= 6 && sum >= 60) {
            return;
        }

        if (k >= num) {
            string d = to_string(sum / 60) + ":";
            if(sum % 60 < 10) d += "0";
            d += to_string(sum % 60);
            result.push_back(d);
            return;
        }

        for (int i = l;i < 10;i ++) {
            countDigits(k + 1,i + 1,sum + d[i],num);
        }
    }
};
