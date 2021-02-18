class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> v;
        addingpar(v, "", n, 0);
        return v;
    }

private:
    void addingpar(vector<string> &v, string str, int n, int index) {

        if (n == 0 && index == 0) {
            v.push_back(str);
            return;
        }

        if (index > 0) {
            addingpar(v, str + ")", n, index - 1);
        }

        if (n > 0) {
            addingpar(v, str + "(", n - 1, index + 1);
        }
    }
};
