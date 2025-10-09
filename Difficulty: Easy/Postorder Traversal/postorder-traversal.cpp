/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        Node *curr = root;
        while (curr) {
            if (!curr->right) {
                res.push_back(curr->data);
                curr = curr->left;
            } else {
                Node *pred = curr->right;
                while (pred->left && pred->left != curr) pred = pred->left;
                if (!pred->left) {
                    res.push_back(curr->data);
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    pred->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};