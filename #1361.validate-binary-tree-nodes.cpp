class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int x = findParent(i, parent);
            if (leftChild[i] != -1) {
                int y = findParent(leftChild[i], parent);
                if (x == y) {
                    return false;
                }
                parent[leftChild[i]] = i;
            }

            if (rightChild[i] != -1) {
                int y = findParent(rightChild[i], parent);
                if(x == y) {
                    return false;
                }
                parent[rightChild[i]] = i;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }

            if (count >= 2) {
                return false;
            }
        }
        return true;
    }

private:
    int findParent(int node, vector<int> &parent) {

        if (node == parent[node]) {
            return node;
        }

        return findParent(parent[node], parent);
    }
};
