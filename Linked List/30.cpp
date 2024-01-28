// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp !=NULL && temp->next != NULL){
            ListNode* nextNode = temp->next;
            while(nextNode != NULL && nextNode->val == temp->val){
                ListNode* dupli = nextNode;
                nextNode = nextNode->next;
                delete dupli;
            }
            temp->next = nextNode;
            temp = temp->next;
        }
        return head;
    }
};
