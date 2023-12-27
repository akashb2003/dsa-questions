// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false

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

    ListNode* rev(ListNode* head){
        if(head ==NULL || head->next == NULL) return head;
        
        ListNode* newHead = rev(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        while( f->next != NULL && f->next->next != NULL){
            s=s->next;
            f = f->next->next;
        }
        ListNode* newHead = rev(s->next);\
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){
            if(first->val != second->val){
                return false;
            }
            first = first-> next;
            second = second->next;
        }
        return true;
    }
};
