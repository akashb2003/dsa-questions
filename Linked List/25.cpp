// Problem statement
// You're given a positive integer represented in the form of a singly linked-list of digits. The length of the number is 'n'.
// Add 1 to the number, i.e., increment the given number by one.
// The digits are stored such that the most significant digit is at the head of the linked list and the least significant digit is at the tail of the linked list.

// Example:
// Input: Initial Linked List: 1 -> 5 -> 2
// Output: Modified Linked List: 1 -> 5 -> 3

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

int helper(Node *temp){
    if(temp == NULL) return 1;
    int carry = helper(temp->next);

    temp->data+= carry;
    if(temp->data <10) return 0;
    else{
        temp->data = 0;
        return 1;
    }
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = helper(head);
    if(carry == 1){
        Node *newnode = new Node(1);
        newnode->next = head;
        head = newnode;
    }
    return head;
    
}
