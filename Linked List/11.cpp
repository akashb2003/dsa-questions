// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move to the node at position left-1
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Reverse the sublist from position left to position right
        ListNode* current = prev->next;
        ListNode* next = nullptr;
        ListNode* temp = nullptr;

        for (int i = 0; i <= right - left; ++i) {
            temp = current->next;
            current->next = next;
            next = current;
            current = temp;
        }

        // Connect the reversed sublist back to the rest of the list
        prev->next->next = current;
        prev->next = next;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
