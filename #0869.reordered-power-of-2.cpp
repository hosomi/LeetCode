class Solution {
public:
    bool reorderedPowerOf2(int n) {

        vector<int> count = this->count(n);
        for (int i = 0; i < 31; i++) {
            if (count == this->count(1 << i)) {
                return true;
            }
        }
        return false;
    }

private:
    vector<int> count(int n) {

        vector<int> result(10);
        while (n) {
            result[n % 10]++;
            n /= 10;
        }
        return result;
    };
};
