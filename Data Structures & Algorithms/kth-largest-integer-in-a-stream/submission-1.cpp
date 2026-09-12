class KthLargest {
private:
    priority_queue<int> maxh;
    int k;

public:
    KthLargest(int k, vector<int>& nums) : maxh(nums.begin(), nums.end()) {
        this->k = k;
    }
    
    int add(int val) {
        maxh.push(val);
        vector<int> tmp;
        for (int i = 0; i < k - 1; i++) {
            tmp.push_back(maxh.top());
            maxh.pop();
        }
        int max = maxh.top();

        for (int i = 0; i < k - 1; i++) {
            maxh.push(tmp.back());
            tmp.pop_back();
        }



        return max;
    }
};
