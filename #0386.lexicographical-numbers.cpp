class Solution {
public:
    vector<int> lexicalOrder(int n) {

        for (int i=1; i <= 9; i++) {
            if (i <= n) {
                dfs(i,n);
            }
        }
        return result;
    }

private:
    vector<int> result;

    void dfs(int i, int n) {

        result.push_back(i);
        for (int j = 0; j <= 9; j++) {
            if (i * 10 + j <= n) {
                dfs(i * 10 + j, n);
            } else {
                break;
            }
        }
    }
};
