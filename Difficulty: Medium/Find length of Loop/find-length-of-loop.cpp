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
    int lengthOfLoop(Node* head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                int len = 0;
                do {
                    f = f->next;
                    len++;
                } while (s != f);
                return len;
            }
        }
        return 0;
    }
};
