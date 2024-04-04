// You are given ‘q’ queries, where each query can be of the following types:

// (1) 1 x -> this means to push the element ‘x’ in the queue.
// (2) 2 -> This means deleting the front element of the queue and returning it. If there’s no element in the queue, return -1.
// Your task is to implement a queue that supports these two queries.



// You must write an algorithm whose time complexity is O(1), and whose space complexity is O(1).



// Note:
// In the output, you will see the output of queries of type 2. 
// In the queries, there will be at least one type 2 query.
// You will be given two functions, ‘push’, and ‘pop’. 
// Your task is to implement the two functions.


// Example:
// Input: ‘q’ = 5
// ‘queries’ = [[1 3], [2], [1 4], [2], [2]]

// Output: 3 4 -1

/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */
void Queue::push(int x) {
    if(front == NULL && rear == NULL){
        Node *  temp = new Node(x);
        //temp->next = nullptr;
        front = temp;
        rear = temp;
    }
    else {
     Node *  temp = new Node(x);
     rear->next = temp;
     rear= temp;
    }


}

int Queue::pop() {
    if(rear == NULL && front == NULL) return -1;
    else{
        if(rear == front){
        int temp = front->data;
        rear = nullptr;
        front = NULL;
        return temp;
        }
        else{
        int temp = front->data;
        front= front->next;
        return temp;
        }
    }
}
