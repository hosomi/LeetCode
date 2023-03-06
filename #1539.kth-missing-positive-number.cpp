class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int left = 0;
        int right = arr.size();
        int mid;
        while (left < right) {
            mid = (left + right + 1) >> 1;
            if(mid == 0 || arr[mid - 1] - mid < k){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        
        return left + k;
    }
};
