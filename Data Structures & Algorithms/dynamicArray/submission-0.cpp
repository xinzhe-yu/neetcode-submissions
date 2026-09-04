class DynamicArray {

private: 
    int* arr; 
    int length; // currently stored
    int capacity; // max before resize

public:

    DynamicArray(int capacity) {
        //if (capacity < 0) { return; }
        arr = new int[capacity];
        length = 0; 
        this->capacity = capacity; 
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        // push back of arr
        arr[length] = n; 
        length++;
    }

    int popback() {
        if (length > 0) {
            length--;
        }
        return arr[length];

    }

    void resize() {
        capacity *= 2; 
        int* temp_arr = new int[capacity];
        for (int i = 0; i < length; i++) {
            temp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = temp_arr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
