// Problem statement
// You have to implement the pop function of Max Priority Queue and implement using a heap.



// Functions :
// a) push(int x) : 'x' has to be inserted in the priority queue. This has been implemented already

// b) pop() : return the maximum element in the priority queue, if priority queue is empty then return '-1'.

int pop(vector<int> &heap)
{
    // Write you code here.
    if(heap.empty()) return -1;

    int size = heap.size();
    int ans = heap[0];
    heap[0] = heap[size-1];
    size--;
    heap.pop_back();
    int i=0;
    
    while(i<size){
        int p = i;
        int li = 2*i+1;
        int ri = 2*i+2;

        if(li< size && heap[li]>heap[p]){
            p = li;
        }
        if(ri<size && heap[ri]>heap[p]){
            p = ri;
        }
        if(i!= p){
            swap(heap[i],heap[p]);
            i = p;
        }
        else{
            return ans;

        }
    }
    return ans;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }
