#include <stack>

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        if (min_stack.empty() || min_stack.top() >= val) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if (data.empty()) {
            return;
        }

        int val = data.top();
        data.pop();
        if (val == min_stack.top()) {
            min_stack.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
    std::stack<int> data;
    std::stack<int> min_stack;
};

