class Solution {
public:
    int numTilePossibilities(string tiles) {

        unordered_map<char, int> tile;
        vector<int> num;
        for (auto &c : tiles) {
            if (tile .find(c) == tile.end()) {
                tile[c] = num.size();
                num.push_back(0);
            }
            num[tile[c]]++;
        }
        result = 0;
        numTilePossibilities(num);
        return result - 1;
    }

private:
    int result;

    void numTilePossibilities(vector<int> &num) {

        result++;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > 0) {
                num[i]--;
                numTilePossibilities(num);
                num[i]++;
            }
        }
    }
};
