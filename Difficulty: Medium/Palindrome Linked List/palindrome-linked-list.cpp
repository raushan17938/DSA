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
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverseList(slow->next);
        Node* firstHalf = head;
        Node* tempSecond = secondHalf;

        bool isPalin = true;
        while (tempSecond != NULL) {
            if (firstHalf->data != tempSecond->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }

        slow->next = reverseList(secondHalf);

        return isPalin;
    }
};