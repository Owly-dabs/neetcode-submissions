class MinStack {
public:
    stack<int> s;
    stack<int> minS;
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        if (minS.empty()) minS.push(val);
        else {
            if (minS.top() > val) minS.push(val);
            else minS.push(minS.top());
        }
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
