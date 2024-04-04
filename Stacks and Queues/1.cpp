// Stack is a data structure that follows the LIFO (Last in First out) principle. Design and implement a stack to implement the following functions:

// 1. Push(num): Push the given number in the stack if the stack is not full.

// 2. Pop: Remove and print the top element from the stack if present, else print -1.

// 3. Top: Print the top element of the stack if present, else print -1.

// 4. isEmpty: Print 1 if the stack is empty, else print 0.

// 5. isFull: Print 1 if the stack is full, else print 0.

// Stack class.

class Stack {

    

public:

    int Top;

    int* arr;

    int capacity;

    Stack(int capacity) {

        // Write your code here.

        this->capacity=capacity;

        arr= new int[capacity];

        Top=-1;

    } 


 

    void push(int num) {

        // Write your code here.

        if(isFull())

            return ;


 

        Top++;

        arr[Top]= num;

    }


 

    int pop() {

        // Write your code here.

        if(isEmpty())

            return -1;

        int val=arr[Top];

        Top--;

        return val;

    }

    

    int top() {

        // Write your code here.

        if(isEmpty())

            return -1;

        else

            return arr[Top];

    }

    

    int isEmpty() {

        // Write your code here.

        if(Top==-1)

            return 1;

        else

            return 0;

    }

    

    int isFull() {

        // Write your code here.

        if(Top==capacity-1)

            return 1;

        else

            return 0;

    }

    

};

