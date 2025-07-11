/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
*/

void QueueStack::push(int x) {
 
    q2.push(x);
    
   
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
 
    swap(q1, q2);
}

int QueueStack::pop() {
    if (q1.empty())
        return -1;  
    
    int top = q1.front();
    q1.pop();
    return top;
}
