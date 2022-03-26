class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) {
            move();
        }
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if (out.empty()) {
            move();
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }

    void move() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    stack<int> in;
    stack<int> out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
