class MinHeap {
   private:
    vector<int> heap;

   public:
    MinHeap() { heap.push_back(0); }

    void push(int val) {
        heap.push_back(val);

        // percolate upwards
        int i = heap.size() - 1;
        while (i > 1 && heap[i] < heap[i / 2]) {
            // swap
            int tmp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = tmp;
            i = i / 2;
        }
    }

    int pop() {
        if (heap.size() <= 1) {
            return -1;
        }
        if (heap.size() == 2) {
            int res = heap.back();
            heap.pop_back();
            return res;
        }
        int top = heap[1];
        // swap top with last
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();

        // percolate downwards from root
        // properties = if child exist, left node exists

        int i = 1;
        while (2 * i < heap.size()) { // left exist
            if (2 * i + 1 < heap.size() && heap[2*i+1] < heap[2*i] && heap[i] > heap[2*i+1]) { //right exist
                // sawp
                int tmp = heap[i];
                heap[i] = heap[i * 2 + 1];
                heap[i*2+1] = tmp;
                i = i * 2 + 1;
            } else if (heap[i] > heap[2*i]) {
                int tmp = heap[i];
                heap[i] = heap[i*2];
                heap[i*2] = tmp;
                i = i * 2;
            } else {
                break;
            }
        }
        return top;
    }

    int top() {
        if (heap.size() <= 1) {
            return -1;
        } else {
            return heap[1];
        }
    }

    void heapify(vector<int> arr) {
        heap = {0};
        for (int x : arr) {
            heap.push_back(x);
        }

        int curr = (heap.size() - 1) / 2;
        while (curr > 0) {
            int i = curr;
            while (2 * i < heap.size()) { // left exist
                if (2 * i + 1 < heap.size() && heap[2*i+1] < heap[2*i] && heap[i] > heap[2*i+1]) { //right exist
                    // sawp
                    int tmp = heap[i];
                    heap[i] = heap[i * 2 + 1];
                    heap[i*2+1] = tmp;
                    i = i * 2 + 1;
                } else if (heap[i] > heap[2*i]) {
                    int tmp = heap[i];
                    heap[i] = heap[i*2];
                    heap[i*2] = tmp;
                    i = i * 2;
                } else {
                    break;
                }
            }
            curr--;
        }

    }
};