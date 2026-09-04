class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int, int>> s; 
        vector<int> ans(temperatures.size());

        //s.push({temperatures[0], 0})
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                // calc distance
                int diff = i - s.top().second;
                ans[s.top().second] = diff;
                s.pop();
            }
            if (s.empty() || temperatures[i] <= s.top().first) { // less than equal
                s.push({temperatures[i], i});
            }
        }

        while (!s.empty()) {
            int i = s.top().second;
            ans[i] = 0;
            s.pop();
        }

        return ans;

    }
};
