class Solution {
public:
    long long countOfSubstrings(string word, int k) {

        return helper(word, k) - helper(word, k + 1);
    }

private:
    long long helper(string word, int k) {

        string vowels = "aeiou";
        int n = word.size();
        long long ans = 0;
        long long i = 0;
        long long cnt[6] = {};
        long long totalUnique = 0;
        for (int j = 0; j < n; j++) {
            char ch = word[j];
            int isVowel = vowels.find(ch) + 1;
            cnt[isVowel]++;
            totalUnique += (isVowel && cnt[isVowel] == 1);
            while (totalUnique == 5 && cnt[0] >= k) {
                ans += n - j;
                isVowel = vowels.find(word[i++]) + 1;
                cnt[isVowel]--;
                totalUnique -= (isVowel && cnt[isVowel] == 0);
            }
        }
        return ans;
    }
};
