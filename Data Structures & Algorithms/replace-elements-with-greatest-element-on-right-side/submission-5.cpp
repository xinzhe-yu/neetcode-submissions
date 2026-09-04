class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //swap last number with -1, size(list); list[lastnumber] = -1


        int size = arr.size();
        for (int i = 0; i < size - 1; i++) {
            auto it = max_element(arr.begin() + i + 1, arr.end()) - arr.begin();
            int index = (int)it;

            arr[i] = arr[index];
        }
        arr[size-1] = - 1;
      
        return arr;
        
    }
};
