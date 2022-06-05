class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {

        int size = releaseTimes.size();
        int time = releaseTimes[0];
        char result = keysPressed[0];
        for (int i = 1; i < size; i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            if (time < currentDuration) {
                result = keysPressed[i];
                time = currentDuration;
            }  else if (time == currentDuration) {
                result = std::max(result, keysPressed[i]);
                time = currentDuration;
            }
        }
        return result;
    }
};
