

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int running_max = -1;

        for (int i = arr.size() -1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = running_max;
            running_max = std::max(temp, running_max);
            
        }

        return arr;
    }
};