class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int count =0;
        for (int i = low; i <= high; i++) {
            string nums = to_string(i);
            int size = nums.size();
            if (size % 2 == 0) {
                int sumLeft = 0;
                int sumRight =0;
                for (int j = 0; j < size / 2; j++) {
                    sumLeft += nums[j];
                    sumRight += nums[size - j - 1];
                }

                if (sumLeft == sumRight) {
                    count++;
                }
            }
        }
        return count;
    }
};
