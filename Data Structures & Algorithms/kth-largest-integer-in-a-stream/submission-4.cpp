class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minh;
    
    int k; 

    // min heap of size k 
    // return top 
public:
    KthLargest(int k, vector<int>& nums) : minh(nums.begin(), nums.end()) {
        this->k = k;
        while (minh.size() > k) {
            minh.pop();
        }
    }
    
    int add(int val) {
        minh.push(val);
        while (minh.size() > k) {
            minh.pop();
        }
        return minh.top();
    }
};
