class NumArray {
private:
    vector<int> prefix; 
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left < 1) {
            return prefix[right];
        }
        return (prefix[right] - prefix[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */