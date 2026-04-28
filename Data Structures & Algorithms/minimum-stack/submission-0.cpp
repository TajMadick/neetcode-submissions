class MinStack {
public:
    stack<int> st;
    map<int, int> min;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);

        if (min.contains(val))
        {
            min[val] ++;
        }
        else
        {
            min.insert({val, 1});
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();

        if (min[val] == 1)
        {
            min.erase(val);
        }
        else
        {
            min[val] --;
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.begin()->first;
    }
};
