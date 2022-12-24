class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int size = arr.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
    
        if (sum % 3 != 0 ) {
            return false;
        }

        int threeParts = sum / 3;
        int counter = 0;
        sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
            if (sum == threeParts) {
                   counter += 1;
                   sum = 0;
            }
        }
        return counter >= 3;
    }
};
