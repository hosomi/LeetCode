/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {

        Node *nhead = nullptr;
        Node *nprev = nullptr;
        Node *cursor = root;
        while (cursor) {
            while (cursor) {
                if (cursor->left) {
                    if (nprev) {
                        nprev->next = cursor->left;
                    } else {
                        nhead = cursor->left;
                    }
                    nprev = cursor->left;
                }

                if (cursor->right) {
                    if (nprev) {
                        nprev->next = cursor->right;
                    } else {
                        nhead = cursor->right;
                    }
                    nprev = cursor->right;
                }
                cursor = cursor->next;
            }

            cursor = nhead;
            nprev = nhead = nullptr;
        }
        return root;
    }
};
