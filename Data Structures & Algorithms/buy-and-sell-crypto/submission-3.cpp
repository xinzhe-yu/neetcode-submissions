class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int profit = 0; 
        for (int R = 0; R < prices.size(); R++) {
            cout << L << "\n";
            if (prices[R] < prices[L]) {
                L = R; 
            }
            int tmp = prices[R] - prices[L];
            profit = max(tmp, profit);
        }

        return profit;
    }
};
