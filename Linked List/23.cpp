// Problem statement
// Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
// Example:
// Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.

/*
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
*/

Node* sortList(Node *head){
    // Write your code here.
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroHead = new Node(-1);

    Node *one = oneHead;
    Node *two = twoHead;
    Node *zero = zeroHead;

    Node *temp = head;

    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
            temp = temp->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
            temp = temp->next;
        }
        else{
            two->next = temp;
            two = temp;
            temp = temp->next;
        }
    }

    zero->next = (oneHead->next) ? oneHead->next: twoHead->next;
    one->next  = twoHead->next;
    two->next  = nullptr;

    Node *newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
