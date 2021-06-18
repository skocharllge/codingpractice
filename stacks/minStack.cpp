class MinStack {
public:
    stack<int>myStack;
    stack<int>minStack;
    
    /** initialize your data structure here. */
    MinStack() {
        
        
    }
    
    void push(int val) {
        
        myStack.push(val);
        
        int element = -1;
       
        if(!minStack.empty())
        {
            element = minStack.top();
            if( val <= element)
            {
                minStack.push(val);
            }
        }
        else
        {
            minStack.push(val);
        }
       
        
    }
    
    void pop() {
        
        auto element1 = minStack.top();
        auto element2 = myStack.top();
        
        if(element1 == element2)
        {
            minStack.pop();
        }
        myStack.pop();
    }
    
    int top() {
        
        return myStack.top();
    }
    
    int getMin() {
        
        return minStack.top();
        
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
