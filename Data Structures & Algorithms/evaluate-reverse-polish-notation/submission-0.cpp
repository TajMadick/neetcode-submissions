class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a;
        int b;
        int result;

        stack<int> st;

        for (string str: tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();

                if (str == "+") result = a + b;
                if (str == "-") result = a - b;
                if (str == "*") result = a * b;
                if (str == "/") result = a / b;
                st.push(result);
            }
            else
            {
                st.push(std::stoi(str));
            }
        }

        return st.top();
    }
};
