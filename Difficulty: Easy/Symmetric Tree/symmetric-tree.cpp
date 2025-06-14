/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
 public:
    bool isSymmetric(Node* r){
        if(!r) return true;
        stack<Node*> s1,s2;
        s1.push(r->left);
        s2.push(r->right);
        while(!s1.empty()){
            Node* u=s1.top(); s1.pop();
            Node* v=s2.top(); s2.pop();
            if(!u&&!v) continue;
            if(!u||!v||u->data!=v->data) return false;
            s1.push(u->left);  s2.push(v->right);
            s1.push(u->right); s2.push(v->left);
        }
        return true;
    }
};