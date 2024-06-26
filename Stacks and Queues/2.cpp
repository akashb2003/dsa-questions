// Queue is a linear data structure that follows the idea of First In First Out. That means insertion and retrieval operations happen at opposite ends.



// Implement a simple queue using arrays.



// You are given 'query' queries which are either of the 2 types:



// 1 'e': Enqueue (add) element ‘e’ at the end of the queue.

// 2: Dequeue (retrieve) the element from the front of the queue. If the queue is empty, return -1.



// Example:
// Input: Queries: 
//              [ 1 2,
//                1 7,
//                2,
//                1 13, 
//                2, 
//                2, 
//                2 ]

// Output:
//          [ 2, 
//            7, 
//            13,  
//            -1 ]

// Explanation: After each operation, our queue is equal to the following:
// 1 2: {2}
// 1 7: {2, 7}
// 2: {7} and 2 is printed
// 1 13: {7, 13}
// 2: {13} and 7 is printed
// 2: {} and 13 is printed
// 2: {} and -1 is printed since the queue is empty.

class Queue {

 

    int front, rear;

    vector<int> arr;

 

public:

    Queue()

    {

        front = 0;

        rear = 0;

        arr.resize(100001);

    }

 

    // Enqueue (add) element 'e' at the end of the queue.

    void enqueue(int e)

    {

        // Write your code here.

                if (rear < arr.size()) {

                  arr[rear] = e;

 

                  rear++;

                }

                

        }

 

    // Dequeue (retrieve) the element from the front of the queue.

    int dequeue()

    {

        // Write your code here.

        if (front==rear){

            return -1;

        }

        else{

            int deqval=arr[front];

            front++;

            return deqval;

        }

    }

};
