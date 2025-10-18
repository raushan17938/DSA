/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int findMedian(Node* root) {
        int n = 0, k = 0, med = -1;
        Node* c = root;
        while (c) {
            if (!c->left) { n++; c = c->right; }
            else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else { p->right = nullptr; n++; c = c->right; }
            }
        }
        k = (n + 1) / 2;
        c = root;
        while (c) {
            if (!c->left) {
                if (++med == k - 1) return c->data;
                c = c->right;
            } else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else {
                    p->right = nullptr;
                    if (++med == k - 1) return c->data;
                    c = c->right;
                }
            }
        }
        return -1;
    }
};