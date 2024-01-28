// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



// You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.



// Find out all the pairs in the doubly linked list with sum equal to 'k'.



// Example :
// Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5

// Output: (1, 4) and (2, 3)

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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node* findTail(Node *head){
    Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    Node *left = head, *right = findTail(head);
    vector<pair<int, int>> ans;

    while(left->data < right->data){
        if(left->data + right->data == k){
            ans.push_back({left->data,right->data});
            left = left->next;
            right= right->prev;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }
    return ans;
}
