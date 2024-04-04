// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while(st.empty() == false) st.pop();
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if(val<mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el < mini)
        {
            mini = 2 * mini - el; 
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;

        long long el = st.top();
        if(el<mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};
