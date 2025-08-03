class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int n = fruits.size();
        int leftsize = n;
        vector<long long> sumleft;
        vector<long long> distleft;
        for (int i = 0; i < n; i++) {
            if (fruits[i][0] >= startPos) {
                leftsize = i; break;
            }
            sumleft.push_back(fruits[i][1]);
            distleft.push_back(startPos - fruits[i][0]);
        }

        sumleft.push_back(0);
        distleft.push_back(0);
        reverse(sumleft.begin(), sumleft.end()); reverse(distleft.begin(), distleft.end());

        vector<long long> sumright;
        vector<long long> distright;
        if (leftsize == n || fruits[leftsize][0] != startPos) {
            sumright.push_back(0);
            distright.push_back(0);
        }

        for(int j = leftsize; j < n; j++){
            sumright.push_back(fruits[j][1]); distright.push_back(fruits[j][0] - startPos);
        }

        leftsize = distleft.size();
        long long rightsize = distright.size();
        for (int i = 1; i < leftsize; i++) {
            sumleft[i] += sumleft[i - 1];
        }

        for (int i = 1; i < rightsize; i++) {
            sumright[i] += sumright[i-1];
        }

        long long ans = 0;
        long long y1;
        long long y2;
        for (int i = 0; i < leftsize; i++) {
            y1 = upper_bound(distright.begin(), distright.end(), k - 2 * distleft[i]) - distright.begin() - 1;
            y2 = upper_bound(distright.begin(), distright.end(), (k - distleft[i]) / 2 ) - distright.begin() - 1;
            
            if (y1 >= 0 && distright[y1] + 2 * distleft[i] <= k) {
                ans = max(ans , sumleft[i] + sumright[y1]);
            }
            if (y2 >= 0 && 2 * distright[y2] + distleft[i] <= k) {
                ans = max(ans , sumleft[i] + sumright[y2]);
            }
        }
        return ans;
    }
};
