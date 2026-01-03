/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeLists(a, b->bottom);
        }
        
        result->next = nullptr;
        return result;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next) {
            return root;
        }

        root->next = flatten(root->next);

        root = mergeLists(root, root->next);

        return root;
    }
};