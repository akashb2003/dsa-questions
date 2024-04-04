// You must implement the Stack data structure using a Singly Linked List.



// Create a class named 'Stack' which supports the following operations(all in O(1) time):



// getSize: Returns an integer. Gets the current size of the stack

// isEmpty: Returns a boolean. Gets whether the stack is empty

// push: Returns nothing. Accepts an integer. Puts that integer at the top of the stack

// pop: Returns nothing. Removes the top element of the stack. It does nothing if the stack is empty.

// getTop: Returns an integer. Gets the top element of the stack. Returns -1 if the stack is empty
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// 3 5
// 3 4
// 1
// 2
// Sample Output 1:
// 2
// false    

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
 

class Stack

{

    //Write your code here  

    Node *top;

    int count;

public:

   

    Stack()

    {

        //Write your code here

       top=NULL;

        count=0;

       

    }

 

    int getSize()

    {

        //Write your code here

        return count;

    }

 

    bool isEmpty()

    {

        //Write your code here

        if(top==NULL){

            return true;

        }else{

         return false;

        }

    }

 

    void push(int data)

    {

        //Write your code here

        Node  *newnode=new Node(data);

        newnode->data=data;

        newnode->next=top;

        top=newnode;

        count++;

    }

 

    void pop()

    {

        //Write your code here

        Node *temp=top;

        if(top==NULL){

            return;

        }

        top=top->next;

        free(temp);

        count--;

 

    }

 

    int getTop()

    {

        //Write your code here

        if(top==NULL){

            return -1;

        }

        return top->data;

    }

};
