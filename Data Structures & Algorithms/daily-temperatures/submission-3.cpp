class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk; 
        vector<int> ans(temperatures.size(), 0); 

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > stk.top().first) {
                // calc distance
                int diff = i - stk.top().second;
                ans[stk.top().second] = diff;
                stk.pop();
            }

            stk.push({temperatures[i], i});

        }

        return ans;
    }
};
