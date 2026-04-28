class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int profit = 0;

        for (int R = 0; R < prices.size(); R++)
        {
            while (prices[L] > prices[R])
            {
                L++;
            }

            profit = max(profit, prices[R] - prices[L]);
        }

        return profit;
    }
};
