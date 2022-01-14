class Solution {
public:
    string originalDigits(string s) {

        vector<int> v(10, 0);
        v[0] = std::count(s.begin(), s.end(), 'z');
        v[2] = std::count(s.begin(), s.end(), 'w');
        v[8] = std::count(s.begin(), s.end(), 'g');
        v[6] = std::count(s.begin(), s.end(), 'x');
        v[3] = std::count(s.begin(), s.end(), 't')- v[2] - v[8];
        v[4] = std::count(s.begin(), s.end(), 'r')- v[3] - v[0];
        v[7] = std::count(s.begin(), s.end(), 's')- v[6];
        v[1] = std::count(s.begin(), s.end(), 'o')- v[4] - v[2] - v[0];
        v[5] = std::count(s.begin(), s.end(), 'v')- v[7];
        v[9] = std::count(s.begin(), s.end(), 'i')- v[8] - v[6] - v[5];
        string c;
        for(int i = 0; i < 10; i++) {
            if (v[i] > 0) {
                c += string(v[i], '0' + i);
            }
        }
        return c;
    }
};
