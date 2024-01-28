// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



// You are given a sorted doubly linked list of size 'n'.



// Remove all the duplicate nodes present in the linked list.



// Example :
// Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

// Output: Modified Linked List: 1 <-> 2 <-> 3

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        Node *nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;
        
        temp = temp->next;
    }
    return head;
}
