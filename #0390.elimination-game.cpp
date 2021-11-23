class Solution {
public:
    int lastRemaining(int n) {

        int start = 1;
        int end = n;
        int duration = 1;
        bool deleted = true;
        while (start < end) {
            int x = (end - start + duration) / duration;
            if (deleted) {
                if (x % 2 == 1) {
                    end -= duration;
                }
                start += duration;
                deleted = false;
            } else {
                if (x % 2 == 1) {
                    start += duration;
                }
                end -= duration;
                deleted = true;
            }
            duration *= 2;
        }
        return start;
    }
};
