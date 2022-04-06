class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        long result = 0;
        long mod = 1e9+7;
        int size = arr.size();
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < size - 2; i++) {
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target) {
                    int j = 1;
                    int k = 1;
                    while( left < right && arr[left]==arr[left+1] ) {
                        left++;
                        j++;
                    }
                    
                    while(left < right && arr[right]==arr[right-1]) {
                        right--;
                        k++;
                    }
                    result += (arr[left] == arr[right] ? j * (j - 1) / 2 : j * k) % mod;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                }
            }
        }
        return result % mod;
    }
};
