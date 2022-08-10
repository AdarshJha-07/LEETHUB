class MinStack {
    long long minele;
    stack<long long>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
     if(st.empty()){
         minele= (long long)val;
         st.push(val);
     }
        else if(val>=minele){
            st.push((long long)val);
        }
        else if(val<minele){
            st.push(1LL*2*val-minele);
            minele=val;
        }
    }
    
    void pop() {
      long long u=st.top();
        if(u>=minele){
            st.pop();
        }
        else{
            minele=1LL*2*minele-u;
            st.pop();
        }
    }
    
    int top() {
     long long u=st.top();
        if(u>=minele)return u;
     
        else if(u<minele){
           
         return minele;
        }
    return u;
    }
    
    int getMin() {
        return minele;
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