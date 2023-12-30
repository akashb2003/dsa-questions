// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:
// Input: head = [1], n = 1
// Output: []

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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        ListNode* s = head;
        for(int i=0; i<n; i++){
            f = f->next;
        }
        if(f == NULL) return head->next;
        while(f->next != NULL){
            s = s->next;
            f = f->next;
        }
        ListNode* temp = s->next;
        s->next = s->next->next;
        delete temp;
        return head;
    }
};
