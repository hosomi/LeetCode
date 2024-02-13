class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        string result = "";
        for (auto w : words) {
            string prev = w;
            reverse(prev.begin(), prev.end());
            if (prev == w) {
                result = w;
                return result;
            }
        }
        return result;
    }
};
