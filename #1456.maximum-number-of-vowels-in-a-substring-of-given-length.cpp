class Solution {
public:
    int maxVowels(string s, int k) {
      
      int size = s.size();
      unordered_set<int> vowel = {'a','e','i','o','u'};
      int count = 0;
      int result = 0;
      for (int i = 0 ; i < size; i++) {
        if (i >= k && vowel.count(s[i-k])) {
            count--;
        }

        if (vowel.count(s[i])) {
           count++; 
        }
        result = std::max(result, count);
      } 
      return result;
    }
};
