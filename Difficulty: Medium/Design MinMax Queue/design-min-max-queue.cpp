class SpecialQueue {
    queue<int> q;
    deque<int> mn, mx;
public:
    void enqueue(int x) {
        q.push(x);
        while (!mn.empty() && mn.back() > x) mn.pop_back();
        mn.push_back(x);
        while (!mx.empty() && mx.back() < x) mx.pop_back();
        mx.push_back(x);
    }
    void dequeue() {
        int f = q.front(); q.pop();
        if (f == mn.front()) mn.pop_front();
        if (f == mx.front()) mx.pop_front();
    }
    int getFront() { return q.front(); }
    int getMin() { return mn.front(); }
    int getMax() { return mx.front(); }
};