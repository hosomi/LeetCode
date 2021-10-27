class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int size = nums.size();
        int i;
        vector<long long> sum(size + 1, 0);
        for (i = 1; i <= size; ++i) {
            sum[i] = sum[i-1]+nums[i-1];
        }
        return mergeSort(sum, 1, size, lower, upper);
    }

private:
    int mergeSort(vector<long long>&sum, int left, int right, int lower, int upper) {

        if(left > right) {
            return 0;
        }
        
        if (left == right) {
            return ((sum[left] >= lower) && (sum[left] <= upper)) ? 1 : 0;
        }

        int mid;
        int i;
        int j;
        int k;
        int result;
        vector<long long> temp(right-left+1,0);
        mid = (left+right)/2;
        result = mergeSort(sum, left,mid, lower, upper) + mergeSort(sum, mid+1,right, lower, upper); 
        for (i = left, j = k = mid + 1; i <= mid; ++i) {
            while (j <= right && sum[j] - sum[i] < lower) {
                ++j;
            }
            while(k <= right && sum[k] - sum[i] <= upper) {
                ++k;
            }
            result += k - j;
        }

        for (i = k = left, j = mid + 1; k <= right; ++k) {
            temp[k - left] = (i <= mid) && (j > right || sum[i] < sum[j]) ? sum[i++] : sum[j++];
        }

        for (k = left; k <= right; ++k) {
            sum[k] = temp[k - left]; 
        }
        return result;
    }
};
