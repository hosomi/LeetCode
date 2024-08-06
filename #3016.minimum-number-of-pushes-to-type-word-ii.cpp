class Solution {
public:
    int minimumPushes(string word) {

        int n = word.length();
        vector<int> arr(26, 0);
        for (int i = 0; i < n; i++) {
            arr[word[i] - 'a'] += 1;
        }

        std::sort(arr.begin(), arr.end(), greater<int>());
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            int tamp = i / 8;
            result += arr[i] * (tamp + 1);
        }
        return result;
    }
};
