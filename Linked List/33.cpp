// You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:
// (1) ‘next’ which points to the next node in the list
// (2) ‘child’ pointer to a linked list where the current node is the head.
// Each of these child linked lists is in sorted order and connected by 'child' pointer.
// Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.

// Example:
// Input: Given linked list is:

// Output:
// 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* list1, Node* list2){
	Node* dummyhead = new Node(-1);
	Node* dummy = dummyhead;
	while(list1 != NULL && list2 != NULL){
		if(list1->data < list2->data){
			dummy->child = list1;
			dummy = list1;
			list1 = list1->child;
		}
		else{
			dummy->child = list2;
			dummy = list2;
			list2 = list2->child;
		}
		dummy->next = NULL;
	}
	if(list1) dummy->child = list1;
	if(list2) dummy->child = list2;

	if(dummyhead->child) dummyhead->child->next = NULL;
	return dummyhead->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL) return head;
	Node* mergerdhead = flattenLinkedList(head->next);
	head = merge(head, mergerdhead);
	return head;
}
