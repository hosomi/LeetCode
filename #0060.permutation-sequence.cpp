class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> sequence(n, 1);
        vector<char> num(n, 1);
        string result;
        for (int i = 1; i < n; i++) {
            sequence[i] = sequence[i - 1] * i;
        }

        for (int i = 0; i < n; i++) {
            num[i] = (i+1) + '0';
        }

        k--;
        int index;
        for (int i = n; i >= 1; i--) {
            index = k / sequence[i - 1];
            k %= sequence[i - 1];
            result.push_back(num[index]);
            num.erase(num.begin() + index);
        }
        
        return result;
    }
};
