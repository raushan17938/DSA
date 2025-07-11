/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack :: sort()
{
   stack<int> s1;
   int x;
   while(!s.empty()){
           x=s.top();
           s.pop();
          while(!s1.empty() && x<s1.top()){
               int y=s1.top();
               s1.pop();
               s.push(y);
           }
           s1.push(x);
       }
   while(!s1.empty()){
       cout<<s1.top()<<" ";
       s1.pop();
   }
}