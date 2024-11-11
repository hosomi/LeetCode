class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieve_of_eratosthenes(max_num);
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                int sub = nums[i] - nums[i + 1] + 1;
                auto it = lower_bound(primes.begin(), primes.end(), sub);
                if (it != primes.end() && *it < nums[i]) {
                    nums[i] -= *it;
                } else {
                    return false;
                }
            }
        }
        return true;
    }


private:
    vector<int> sieve_of_eratosthenes(int number) {

        vector<char> is_prime(number + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= number; i++) {
            if (is_prime[i]) {
                for (int j = i * 2; j <= number; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        for (int i = 0; i <= number; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
};
