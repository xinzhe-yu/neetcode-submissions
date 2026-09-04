class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int R = prices.size() - 1; 
        int sum = 0; 
       

        for (int L = prices.size() - 1; L >= 0; L--) {
            if (prices[L] > prices[R]) {
                R = L;
            }
            else {
                // calc price 
                int tmp = prices[R] - prices[L];
                cout << "R:" << prices[R] << " L:" << prices[L] << " ";
                sum = max(sum, tmp);
            }
        }
        return sum;
    }
};
