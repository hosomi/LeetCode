class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        vector<int> uf('z' + 1, -1);
        for (auto s : equations) {
            if (s[1] == '=') {
                uf[find(uf, s[0])] = find(uf, s[3]);
            }
        }

        for (auto s : equations) {
            if (s[1] == '!' && find(uf, s[0]) == find(uf, s[3])) {
                return false;
            }
        }
        return true;
    }

private:
    int find(vector<int> &uf, int i) {
        return uf[i] == -1 || uf[i] == i ? i : find(uf, uf[i]);
    }
};
