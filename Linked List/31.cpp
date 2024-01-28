// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

ListNode* reverseNodes(ListNode* head){
    ListNode* prevNode = NULL;
    ListNode* temp = head;
    while(temp!= NULL){
        ListNode* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
    return prevNode;
}

ListNode* findkNode(ListNode* head, int k){
    k-=1;
    while(head !=NULL && k>0){
        k--;
        head = head->next;
    }
    return head;
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*  temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kthNode = findkNode(temp,k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseNodes(temp);
            if(temp==head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
