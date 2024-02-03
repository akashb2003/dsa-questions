// Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
// The significance of the bits decreases with the increasing index in the linked list.
// An empty linked list is considered to represent the decimal value 0. 

// Since the answer can be very large, answer modulo 109+7 should be printed.

// Example 1:
// Input:
// n = 3
// Linked List = {0, 1, 1}
// Output:
// 3

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
    {
        // Your Code Here
        if (head == NULL)
        {
            return 0;
        }

        long long int ans = 0;
        struct Node *p = head;
        while (p)
        {
            ans = (ans << 1) | p->data;
            ans = ans % 1000000007;
            p = p->next;
        }

        return ans;
    }
};
