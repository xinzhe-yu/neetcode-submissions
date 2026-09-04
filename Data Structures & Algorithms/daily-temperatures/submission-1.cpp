class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> stk;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > stk.top().first) {
                // calc index
                int diff = i - stk.top().second;
                ans[stk.top().second] = diff;
                stk.pop();
            }

            stk.push( {temperatures[i], i} );

        }
        // one pass = has current index i
        // stores old index in the stack use pairs 
        // if 38>30
        // calc distance 
        return ans;
    }



};
