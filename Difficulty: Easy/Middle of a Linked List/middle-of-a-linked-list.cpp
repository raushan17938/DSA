/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getsize(Node *head)
{
    int c=0;
    while(head)
    {
        c++;
        head=head->next;
    }
    return c;
}
int getMiddle(Node *head)
{
   int l = getsize(head);
   
        int k = (l/2);
        while( k --)
        {
            head=head->next;
        }
        return head->data;
   
}
};