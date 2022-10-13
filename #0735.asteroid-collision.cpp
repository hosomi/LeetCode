class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int size = asteroids.size();
        int index = -1;
        for (int i = 0; i < size; ++i) {
            bool exploded = false;
            while (index >= 0 && asteroids[index] > 0 && asteroids[i] < 0) {
                if (abs(asteroids[index]) > abs(asteroids[i])) {
                    exploded = true;
                    break;
                }
                
                if (abs(asteroids[index]) == abs(asteroids[i])) {
                    --index;
                    exploded = true;
                    break;
                }
                
                --index;
            }
            
            if (!exploded) {
                asteroids[++index] = asteroids[i];
            }
        }
        return vector<int>(asteroids.begin(), asteroids.begin() + index + 1);
    }
};
