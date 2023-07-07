class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
 
        return std::max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
    }

private:
    int helper(string &answerKey, int k, char ch) {

        int size = answerKey.size();
        int m = 0;
        int l = -1;
        int r = 0;
        int result = 0;
        while (r < size) {
            if (answerKey[r] == ch) {
                m++;
            }

            while (m > k) {
                if (answerKey[++l] == ch) {
                    m--;
                }
            }
            result = std::max<int>(result, r++ - l);      
        }
        return result;
    }
};
