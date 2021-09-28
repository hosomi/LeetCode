class Solution {
public:
    vector<string> addOperators(string num, int target) {
        result = vector<string>();
        recursiveAdd(num,target, "", 0, 0);
        return result;
    }

private:
    vector<string> result;
    void recursiveAdd(string num,
                      int target,
                      string e,
                      long p1,
                      long p2) {

        int size = num.size();
        if (p1 == target && size == 0) {
            result.push_back(e);
            return;
        }

        string s1, s2;
        long l;
        for(int i = 1; i <= size; ++i) {
            s1 = num.substr(0,i);
            if (s1.size() > 1 && s1[0] == '0') {
                return;
            }

            s2 = num.substr(i);
            l = std::stol(s1);
            if (e.size() > 0) {
                recursiveAdd(s2, target, e + "*" + s1, p1 - p2 + p2 * l, p2 * l);
                recursiveAdd(s2, target, e + "+" + s1, p1 + l, l);
                recursiveAdd(s2, target, e + "-" + s1, p1 - l, -l);
            } else {
                recursiveAdd(s2, target, s1, l, l);
            }
        }
    }
};
