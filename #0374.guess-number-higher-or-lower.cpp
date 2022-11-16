/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int left = 1;
        int right = n;
        int cursor = left + (right - left) / 2;
        while (true) {
            switch (guess(cursor)){
                case -1:
                    right = cursor - 1;
                    cursor = left + (right - left) / 2;
                    break;
                case 1:
                    left = cursor+1;
                    cursor = left + (right - left) / 2;
                    break;
                case 0:
                    return cursor;
            }
        }
        return 0;
    }
};
