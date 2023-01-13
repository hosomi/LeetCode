class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        
        int size = s.size();
        vector<int> childs(size, 0);
        vector<int> v1(size, 1);
        vector<int> v2(size, 1);
        for (int i = 1; i < size; i++) {
            childs[parent[i]]++;
        }

        queue<int> q;
        for (int i = 1; i < size; i++) {
            if (!childs[i]) {
                q.push(i);
            }
        }

        int result = 1;
        while (q.size() && q.front() != 0) {
            int child = q.front();
            q.pop();
            int p = parent[child];
            if (int length = 1 +
                (s[child] != s[p] ? v1[child] : 0); v1[p] <= length) {
                v2[p] = v1[p];
                v1[p] = length;
            } else{
                v2[p] = std::max(v2[p], length);
            }

            if (--childs[p] == 0) {
                q.push(p);
                result = std::max(result, v1[p] + v2[p] - 1);
            }
        }
        return result;
    }
};
