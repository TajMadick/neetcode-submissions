class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> sol(temperatures.size());
        st.push({temperatures[0], 0});
        
        for (int i = 1; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > st.top().first)
            {
                pair<int,int> top = st.top();
                st.pop();

                sol[top.second] = i - top.second;
            }

            st.push({temperatures[i], i});
        }
        
        while(!st.empty())
        {
            pair<int,int> top = st.top();
            st.pop();

            sol[top.second] = 0;
        }

        return sol;
    }
};
