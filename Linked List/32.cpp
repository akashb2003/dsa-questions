// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

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

ListNode* findNthNode(ListNode* temp, int n){
    n--;
    while(temp!=NULL && n>0){
        n--;
        temp = temp->next;
    }
    return temp;
}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next == NULL) return head;
        
        ListNode* tail = head;
        int c=1;
        while(tail->next != NULL){
            c++;
            tail = tail->next;
        }

        k = k%c;
        if(k==0) return head;
        tail->next = head;
        ListNode* newTail = findNthNode(head, c-k);
        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};
