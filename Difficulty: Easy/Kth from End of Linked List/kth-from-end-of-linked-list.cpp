/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        Node* fast = head;
        Node* slow = head;
        
   
        for (int i = 0; i < k; i++) {
            if (fast == NULL) return -1; 
            fast = fast->next;
        }
        
     
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return (slow != NULL) ? slow->data : -1;
    }
};
