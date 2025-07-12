class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {

        return rec(firstPlayer - 1, secondPlayer - firstPlayer - 1, n-secondPlayer);
    }

private:
    vector<int> rec(int left, int mid, int right) {

        if (left == right){
            return {1,1};
        }

        vector<int> ans = {(int)1e9, - (int)1e9};
        if (left > right) {
            swap(left, right);
        }
        
        int tot = left + 1 + mid + 1 + right;
        for (int n_left = 0; n_left <= left; n_left++) {
            int right_pos = left + 1 + mid + 1;
            if (right_pos > (tot + 1) / 2) {
                for (int right_add = 0; right_add <= tot - right_pos - left - 1; right_add++) {
                    int n_right = left-n_left + right_add;
                    int n_mid = (tot + 1) / 2 - n_left - n_right - 2;
                    auto tmp = rec(n_left, n_mid, n_right);
                    ans[0] = min(ans[0], tmp[0]+1);
                    ans[1] = max(ans[1], tmp[1]+1);
                }
            } else {
                for (int n_mid = 0; n_mid <= right_pos - 1 - left - 1; n_mid++){
                    int n_right = (tot + 1) / 2 - n_left - n_mid - 2;
                    auto tmp = rec(n_left, n_mid, n_right);
                    ans[0] = min(ans[0], tmp[0] + 1); 
                    ans[1] = max(ans[1], tmp[1] + 1); 
                }
            }
        }
        return ans;
    }
};
