class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk; // {temp, index}
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {


            while (!stk.empty() && temperatures[i] > stk.top().first) {
                //calc ans
                int distance = i - stk.top().second; 
                ans[stk.top().second] = distance; 
                stk.pop();
            }

            stk.push({temperatures[i], i});

        }

        while (!stk.empty()) {
            ans[stk.top().second] = 0;
            stk.pop();
        }

        return ans; 
    }
};
