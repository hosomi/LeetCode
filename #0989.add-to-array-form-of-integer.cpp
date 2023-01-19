class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int size = num.size();
        int cur = 0;
        while (k > 0) {
            int cursum;
              if (size-1-cur >= 0){
                cursum = num[size - 1 - cur] + k % 10;
                num[size - 1 - cur] = cursum % 10;
            } else {
                cursum = k % 10;
                num.insert(num.begin(), cursum);
                size++;
            }

            if (size - 1 - (cur + 1) >= 0) {
                num[size - 1 - (cur + 1)] += cursum / 10;
            } else if(cursum / 10 > 0) {
                num.insert(num.begin(), cursum / 10);
                size++;
            }
            k /= 10;
            cur++;
        }

        while (size - 1 - cur >= 0 && num[size - 1 - cur] >= 10) {
            int tmp = num[size - 1 - cur];
            num[size - 1 - cur] = tmp % 10;
            if (size - 1 - (cur + 1) >= 0) {
                num[size - 1 - (cur + 1)] += tmp / 10;
            } else {
                num.insert(num.begin(), tmp / 10);
            }
            cur++;
        }
        return num;
    }
};
