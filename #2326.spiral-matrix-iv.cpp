/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        int curr = 0;
        int curc = 0;
        int curd = 0;
        vector<vector<int>> results = vector(m, vector(n, -1));
        while (head) {
            results[curr][curc] = head->val;
            head = head->next;
            for (int d = 0; d < 4; d++) {
                int nxtd = (curd + d) % 4;
                int nxtr = curr + dr[nxtd];
                int nxtc = curc + dc[nxtd];
                if (isValid(nxtr, nxtc, m, n)
                    && results[nxtr][nxtc] == -1) {
                    curr = nxtr;
                    curc = nxtc;
                    curd = nxtd;
                    break;
                }
            }
        }
        return results;
    }

private:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool isValid(int r, int c, int m, int n) {
        return !(r < 0 || c < 0 || r >= m || c >= n);
    }
};
