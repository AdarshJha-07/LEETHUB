class MinStack {
public:
    
    
    stack<long long> s;
    
    long long minValue;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(s.empty()){
            s.push(val);
            minValue = val;
        }
        else if(val >= minValue){
            s.push(val);
        }
        else{
            long long x = (long long)val + (long long)val - minValue;
            s.push(x);
            minValue = val;
        }
    }
    
    void pop() {
        
        long long val = s.top();
        s.pop();
        
        if(val < minValue){
            minValue = 1LL*2*minValue - val;
        }
    }
    
    int top() {
        
        if(s.top() >= minValue){
            return s.top();
        }
        else{
            return minValue;
        }
        
    }
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */