class Solution {
public:
    bool detectCapitalUse(string word) {

        int size = word.size();
        if (std::isupper(word[0])) {
            if (size < 2) {
                return true;
            }

            if (std::isupper(word[1])) {
                for (int i = 1; i < size; i++) {
                    if (std::islower(word[i])) {
                        return false;
                    }
                }
            } else {
                for (int i = 1; i < size; i++) {
                    if (std::isupper(word[i])) {
                        return false;
                    }
                }
            }
        } else {
            for (int i = 1; i < size; i++) {
                if (std::isupper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};
