class Solution {
public:
    string reverseVowels(string s) {

        int i = 0;
        int index = s.size() - 1;
        string vowels = "aeiouAEIOU";
        char temp;
        while (i < index) {
            while (i < s.size() && vowels.find(s[i]) == std::string::npos) {
                i++;
            }

            while (index >= 0 && vowels.find(s[index]) == std::string::npos) {
                index--;
            }

            if (i < index) {
                temp = s[i];
                s[i] = s[index];
                s[index] = temp;
            }
            i++;
            index--;
        }
        return s;
    }
};
