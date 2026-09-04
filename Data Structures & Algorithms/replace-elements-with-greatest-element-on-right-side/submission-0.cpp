#include <algorithm>
#include <vector>
#include <iostream>


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp = 0;
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            arr[i] = *std::max_element(arr.begin() + i+1, arr.end());

                
            
        }

        arr.back() = -1;

        return arr;
    }
};