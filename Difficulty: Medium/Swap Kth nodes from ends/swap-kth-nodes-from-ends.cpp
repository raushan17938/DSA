/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = 0;
        for (Node* t = head; t; t = t->next) n++;
        if (k > n || 2 * k - 1 == n) return head;
        
        Node *x = head, *y = head, *px = nullptr, *py = nullptr;
        for (int i = 1; i < k; i++) px = x, x = x->next;
        for (int i = 1; i < n - k + 1; i++) py = y, y = y->next;
        
        if (px) px->next = y; else head = y;
        if (py) py->next = x; else head = x;
        
        Node* temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        return head;
    }
};