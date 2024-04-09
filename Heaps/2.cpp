// Implement the Min Heap data structure. For information about Heap click here.

// Min heap is a tree data structure where the root element is the smallest of all the elements in the heap. Also, the children of every node are smaller than or equal to the root node. 

// The insertion and removal of elements from the heap take log('N'), where 'N' is the number of nodes in the tree. 
// Implement the “minHeap” class. You will be given the following types of queries:-

// 0 extractMinElement(): Remove the minimum element present in the heap, and return it.

// 1 deleteElement( i ): Delete the element present at the 'i' th index.

// 2 insert( key ): Insert the value 'key' in the heap.

// For queries of types 0 and 1, at least one element should be in the heap.

class minHeap {
public:

    // Constructor for the class.
    vector<int>heap;
    int size, cap;
    minHeap(int capacity) {
        // Write your code here.
        heap.resize(capacity);
        cap = capacity;
        size = 0;
    }

    void heapify(int i){
        int p = i;
        int li = 2*i+1;
        int ri = 2*i+2;
        if(li<size && heap[li]<heap[p]){
            p = li;
        }
        if(ri<size && heap[ri]<heap[p]){
            p = ri;
        }
        if( i!= p){
            swap(heap[i],heap[p]);
            heapify(p);
        }
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        if(size==0) return -1;
        int ans = heap[0];
        swap(heap[0],heap[size-1]);
        size--;
        heap.pop_back();
        heapify(0);
        return ans;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind>=size) return;
        swap(heap[ind],heap[size-1]);
        size--;
        heap.pop_back();
        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        if(size==cap) return;
        heap[size] = val;
        size++;
        int ind = size-1;
        while(ind>0){
            int p = (ind-1)/2;
            if(heap[p]>heap[ind]){
                swap(heap[p],heap[ind]);
                ind = p;
            }
            else break;
        }
    }
};
