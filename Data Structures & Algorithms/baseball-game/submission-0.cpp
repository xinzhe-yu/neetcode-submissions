class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> ans;
        int n = operations.size();
        for (int i = 0; i < n; i++) {
            if (operations[i] == "C") {
                // Invalidate the previous score
                ans.pop_back();
            } 
            else if (operations[i] == "D") {
                // Record a new score that is the double of the previous score.
                ans.push_back(ans.back() * 2); 
            }
            else if (operations[i] == "+") {
                // Sum of the previous two score
                int temp = ans.back();
                int temp2 = ans[ans.size() - 2];
                ans.push_back(temp + temp2);
            }
            else {
                ans.push_back(stoi(operations[i]));
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};