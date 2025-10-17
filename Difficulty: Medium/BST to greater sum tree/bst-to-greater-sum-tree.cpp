/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
public:
    void transformTree(Node* root) {
        int s = 0;
        function<void(Node*)> f = [&](Node* n) {
            if (!n) return;
            f(n->right);
            int temp = n->data;
            n->data = s;
            s += temp;
            f(n->left);
        };
        f(root);
    }
};