class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> st;
    long long minEle;
    MinStack() {
       
    }
    
    void push(int val) {
       if(st.empty()==true){
           st.push(val);
           minEle=val;
       }
        else{
            if(val>=minEle){
                st.push(val);
            }
            else{
                
                long long tmp=2*(long long)val-minEle;
                st.push(tmp);
                minEle=val;
            }
        }
    }
    
    void pop() {
       
        if(st.top()>minEle) st.pop();
        else{
            minEle=2*minEle-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()==true) return -1;
        if(st.top()>=minEle) return st.top();
        else
            return minEle;
    }
    
    int getMin() {
        
            return minEle;
    }
};
