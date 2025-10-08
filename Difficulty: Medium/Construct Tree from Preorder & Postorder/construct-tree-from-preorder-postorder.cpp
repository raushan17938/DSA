/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        int i = 0;
        return build(pre, post, i, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, int& i, int l, int r) {
        Node* root = new Node(pre[i++]);
        if (l != r) root->left = build(pre, post, i, l, find(post.begin() + l, post.begin() + r, pre[i]) - post.begin());
        if (l != r && i < pre.size()) root->right = build(pre, post, i, find(post.begin() + l, post.begin() + r, root->left->data) - post.begin() + 1, r - 1);
        return root;
    }
};